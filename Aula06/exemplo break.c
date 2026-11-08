#include <stdio.h>
#include <stdlib.h>

int main() {
    // Defina quanta memória você quer dar ao programa (em Megabytes)
    // 1024 MB (1 GB) consegue calcular por volta de 80 milhões de dígitos de PI!
    long long memoria_mb = 1024;
    long long n = (memoria_mb * 1024 * 1024) / sizeof(int);

    int *r = (int *)malloc((n + 1) * sizeof(int));

    if (r == NULL) {
        printf("Erro ao alocar %lld MB de RAM.\n", memoria_mb);
        return 1;
    }

    printf("Memoria de %lld MB alocada com sucesso.\n", memoria_mb);
    printf("Calculando digitos apos a virgula...\n\n");

    // Inicializa o array com o valor base (2)
    for (long long i = 0; i <= n; i++) {
        r[i] = 2;
    }

    int primeiro_digito = 1;

    // Loop infinito de cálculo
    while (1) {
        long long q = 0;

        // Passagem de Spigot (de trás para frente)
        for (long long i = n; i > 0; i--) {
            long long x = r[i] * 10 + q * i;
            r[i] = x % (2 * i - 1);
            q = x / (2 * i - 1);
        }

        // CORREÇÃO AQUI: Atualiza a primeira posição do array corretamente, sem destruir o ponteiro
        r[1] = q % 10;
        q = q / 10;

        // Formatação para mostrar "3." e depois os dígitos seguidos
        if (primeiro_digito) {
            printf("%lld.", q);
            primeiro_digito = 0;
        } else {
            printf("%lld", q);
        }

        fflush(stdout); // Mostra os dígitos na tela em tempo real
    }

    free(r);
    return 0;
}
