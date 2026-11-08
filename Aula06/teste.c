/*
 * pi_bench.c — Benchmark de CPU/RAM calculando dígitos de pi indefinidamente
 *
 * Usa o algoritmo de Chudnovsky com "binary splitting" (o método mais rápido
 * conhecido para calcular pi com precisão arbitrária) sobre a biblioteca GMP.
 *
 * A cada round o programa aumenta a quantidade de dígitos-alvo, recalcula pi
 * do zero, mede tempo de CPU/parede e pico de RAM (RSS) usados naquele round,
 * e imprime as estatísticas. Roda para sempre até Ctrl+C (SIGINT), momento em
 * que imprime um resumo final e sai de forma limpa.
 *
 * Compilar:
 *   gcc -O3 -march=native -o pi_bench pi_bench.c -lgmp -lm
 *
 * Rodar:
 *   ./pi_bench                  # começa em ~1000 dígitos, dobra a cada round
 *   ./pi_bench 5000             # começa em 5000 dígitos
 *   ./pi_bench 5000 1.3         # começa em 5000 dígitos, cresce 30% por round
 *
 * Ctrl+C a qualquer momento encerra e mostra o resumo.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>
#include <math.h>
#include <sys/resource.h>
#include <gmp.h>

static volatile sig_atomic_t g_stop = 0;

static void handle_sigint(int sig) {
    (void)sig;
    g_stop = 1;
}

/* ---------------------------------------------------------------------
 * Binary splitting para a série de Chudnovsky:
 *
 *   1/pi = 12 * sum_{k=0}^{inf} (-1)^k (6k)! (13591409 + 545140134k)
 *                                ------------------------------------
 *                                 (3k)! (k!)^3 640320^(3k + 3/2)
 *
 * Definimos, para cada termo k:
 *   p(k) = 1                                  se k == 0
 *          -(6k-5)(2k-1)(6k-1)                se k >= 1   (carrega o (-1)^k)
 *   q(k) = 1                                  se k == 0
 *          k^3 * 640320^3 / 24                se k >= 1
 *   a(k) = 13591409 + 545140134*k
 *
 * P(a,b) = produto de p(k) para k em (a, b]
 * Q(a,b) = produto de q(k) para k em (a, b]
 * T(a,b) = soma telescópica tal que, no final (a=0, b=N):
 *
 *   pi ≈ Q(0,N) * 426880 * sqrt(10005) / (Q(0,N)*13591409 + T(0,N))
 * ------------------------------------------------------------------- */

/* 640320^3 / 24, constante da série de Chudnovsky */
static const char *Q_CONST_STR = "10939058860032000";

static void bs(long a, long b, mpz_t P, mpz_t Q, mpz_t T, const mpz_t qconst) {
    if (b - a == 1) {
        /* Este intervalo representa exatamente o termo k = b da série
         * (k >= 1; o termo k = 0 é tratado à parte, fora da recursão). */

        /* P = -(6b-5)(2b-1)(6b-1) */
        mpz_set_si(P, 6 * b - 5);
        mpz_mul_si(P, P, 2 * b - 1);
        mpz_mul_si(P, P, 6 * b - 1);
        mpz_neg(P, P);

        /* Q = b^3 * qconst */
        mpz_set_si(Q, b);
        mpz_mul_si(Q, Q, b);
        mpz_mul_si(Q, Q, b);
        mpz_mul(Q, Q, qconst);

        /* a(b) = 13591409 + 545140134*b */
        mpz_t ab;
        mpz_init(ab);
        mpz_set_si(ab, 545140134);
        mpz_mul_si(ab, ab, b);
        mpz_add_ui(ab, ab, 13591409ULL);

        /* T = P * a(b) */
        mpz_mul(T, P, ab);
        mpz_clear(ab);
        return;
    }

    long m = a + (b - a) / 2;

    mpz_t P1, Q1, T1, P2, Q2, T2;
    mpz_inits(P1, Q1, T1, P2, Q2, T2, NULL);

    bs(a, m, P1, Q1, T1, qconst);
    bs(m, b, P2, Q2, T2, qconst);

    /* P = P1*P2 ; Q = Q1*Q2 ; T = T1*Q2 + P1*T2 */
    mpz_mul(P, P1, P2);
    mpz_mul(Q, Q1, Q2);

    mpz_t tmp;
    mpz_init(tmp);
    mpz_mul(tmp, T1, Q2);
    mpz_mul(T, P1, T2);
    mpz_add(T, T, tmp);

    mpz_clear(tmp);
    mpz_clears(P1, Q1, T1, P2, Q2, T2, NULL);
}

/* Calcula pi com aproximadamente `digits` dígitos decimais em `pi_out`.
 * `terms` é o número de termos da série usados (retornado por referência
 * para fins estatísticos). */
static void compute_pi(unsigned long digits, mpf_t pi_out, long *terms_used) {
    /* Cada termo da série de Chudnovsky agrega ~14.1816474 dígitos decimais. */
    long N = (long)(digits / 14.1816474) + 2;
    if (N < 1) N = 1;
    *terms_used = N;

    /* bits de precisão necessários, com folga de segurança */
    unsigned long bits = (unsigned long)(digits * 3.32192809489 + 128);
    mpf_set_default_prec(bits);
    mpf_set_prec(pi_out, bits);

    mpz_t qconst;
    mpz_init_set_str(qconst, Q_CONST_STR, 10);

    mpz_t P, Q, T;
    mpz_inits(P, Q, T, NULL);
    bs(0, N, P, Q, T, qconst);

    /* pi = Q * 426880 * sqrt(10005) / (Q*13591409 + T) */
    mpf_t Qf, Tf, numerator, denominator, sqrt10005;
    mpf_inits(Qf, Tf, numerator, denominator, sqrt10005, NULL);

    mpf_set_z(Qf, Q);
    mpf_set_z(Tf, T);

    mpf_sqrt_ui(sqrt10005, 10005);

    mpf_mul_ui(numerator, Qf, 426880);
    mpf_mul(numerator, numerator, sqrt10005);

    mpf_mul_ui(denominator, Qf, 13591409);
    mpf_add(denominator, denominator, Tf);

    mpf_div(pi_out, numerator, denominator);

    mpf_clears(Qf, Tf, numerator, denominator, sqrt10005, NULL);
    mpz_clears(P, Q, T, NULL);
    mpz_clear(qconst);
}

static double now_seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

static double cpu_seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

static long peak_rss_kb(void) {
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
    return ru.ru_maxrss; /* já em KB no Linux */
}

int main(int argc, char **argv) {
    unsigned long digits = 1000;
    double growth = 2.0; /* fator de crescimento de dígitos por round */

    if (argc >= 2) digits = strtoul(argv[1], NULL, 10);
    if (argc >= 3) growth = strtod(argv[2], NULL);
    if (digits < 10) digits = 10;
    if (growth <= 1.0) growth = 1.1;

    signal(SIGINT, handle_sigint);

    printf("=== Benchmark de pi (Chudnovsky + binary splitting / GMP) ===\n");
    printf("Pressione Ctrl+C para parar e ver o resumo final.\n");
    printf("Dígitos iniciais: %lu | crescimento por round: %.2fx\n\n", digits, growth);

    long round_num = 0;
    double total_wall = 0.0, total_cpu = 0.0;
    unsigned long last_digits = 0;
    long peak_mem_kb = 0;

    while (!g_stop) {
        round_num++;

        mpf_t pi_val;
        mpf_init(pi_val);

        long terms;
        double w0 = now_seconds();
        double c0 = cpu_seconds();

        compute_pi(digits, pi_val, &terms);

        double w1 = now_seconds();
        double c1 = cpu_seconds();

        double wall = w1 - w0;
        double cpu = c1 - c0;
        long rss = peak_rss_kb();

        total_wall += wall;
        total_cpu += cpu;
        last_digits = digits;
        if (rss > peak_mem_kb) peak_mem_kb = rss;

        double digits_per_sec = digits / (wall > 0 ? wall : 1e-9);

        printf("Round %2ld | dígitos: %10lu | termos: %8ld | tempo: %8.3fs "
               "(cpu %8.3fs) | %10.0f dígitos/s | RAM pico: %8ld MB\n",
               round_num, digits, terms, wall, cpu, digits_per_sec, rss / 1024);
        fflush(stdout);

        mpf_clear(pi_val);

        if (g_stop) break;

        double next = (double)digits * growth;
        digits = (unsigned long)next;
        if (digits <= last_digits) digits = last_digits + 1;
    }

    printf("\n=== Resumo ===\n");
    printf("Rounds completados : %ld\n", round_num);
    printf("Último tamanho     : %lu dígitos\n", last_digits);
    printf("Tempo total (parede): %.3f s\n", total_wall);
    printf("Tempo total (CPU)   : %.3f s\n", total_cpu);
    printf("Pico de RAM         : %ld MB\n", peak_mem_kb / 1024);
    printf("Encerrado pelo usuário (SIGINT).\n");

    return 0;
}
