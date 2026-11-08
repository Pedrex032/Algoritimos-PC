#include <stdio.h>              /* Biblioteca de entrada/saída: fornece printf e scanf */

#define OPS 3                   /* Constante: número de operadoras (linhas da matriz) */
#define MESES 12                /* Constante: número de meses (colunas da matriz) */

int main(void) {                /* Função principal: é aqui que o programa começa */

    /* Vetor de textos com o nome de cada mês; o índice 0 é "jan", o 11 é "dez" */
    const char *meses[] = {"jan", "fev", "mar", "abr", "mai", "jun",
                           "jul", "ago", "set", "out", "nov", "dez"};

    /* Vetor de textos com o nome de cada operadora; índice 0 = Vivo, 1 = Claro, 2 = TIM */
    const char *operadoras[] = {"Vivo", "Claro", "TIM"};

    int vendas[OPS][MESES];     /* Matriz 3x12: vendas[operadora][mês] guarda os chips vendidos */

    int i, j;                   /* Contadores dos laços: i percorre operadoras, j percorre meses */
    int totalGeral = 0;         /* Acumula a soma de TODOS os elementos da matriz; começa em 0 */
    int totalOp[OPS];           /* Vetor: soma anual de cada operadora (uma por linha) */
    int totalMes[MESES];        /* Vetor: soma de cada mês nas três operadoras (uma por coluna) */

    /* ===== ENTRADA DE DADOS ===== */
    printf("=== ENTRADA DE DADOS ===\n");                   /* Mostra o título da etapa de entrada */
    printf("Informe a quantidade de chips vendidos.\n\n");  /* Instrução para o usuário; \n\n pula duas linhas */

    for (i = 0; i < OPS; i++) {                  /* Laço externo: repete uma vez para cada operadora */
        printf("Operadora %s:\n", operadoras[i]); /* Avisa de qual operadora serão os próximos dados */
        for (j = 0; j < MESES; j++) {            /* Laço interno: repete uma vez para cada mês */
            do {                                 /* Início do bloco que repete até o valor ser válido */
                printf("  %s: ", meses[j]);      /* Pede o valor do mês atual (ex.: "  jan: ") */
                scanf("%d", &vendas[i][j]);      /* Lê um inteiro do teclado e guarda na posição [i][j] */
                if (vendas[i][j] < 0) {          /* Se o usuário digitou um valor negativo... */
                    printf("  Valor invalido. Digite um numero maior ou igual a 0.\n"); /* ...avisa o erro */
                }
            } while (vendas[i][j] < 0);          /* Repete a leitura enquanto o valor for negativo */
        }                                        /* Fim do laço dos meses */
        printf("\n");                            /* Linha em branco para separar uma operadora da outra */
    }                                            /* Fim do laço das operadoras */

    /* ===== ZERAR ACUMULADORES ===== */
    for (i = 0; i < OPS; i++)   totalOp[i] = 0;  /* Coloca 0 em cada total de operadora antes de somar */
    for (j = 0; j < MESES; j++) totalMes[j] = 0; /* Coloca 0 em cada total de mês antes de somar */

    /* ===== SOMAS: uma única passagem pela matriz ===== */
    for (i = 0; i < OPS; i++) {                  /* Percorre as operadoras (linhas) */
        for (j = 0; j < MESES; j++) {            /* Percorre os meses (colunas) */
            totalOp[i]  += vendas[i][j];         /* Soma a venda na linha: total anual da operadora i */
            totalMes[j] += vendas[i][j];         /* Soma a venda na coluna: total do mês j (3 operadoras) */
            totalGeral  += vendas[i][j];         /* Soma a venda no total geral da matriz inteira */
        }
    }

    /* ===== 1) MÉDIA MENSAL GERAL ===== */
    int n = OPS * MESES;                         /* Quantidade total de elementos: 3 x 12 = 36 */
    int mediaGeral = (totalGeral + n - 1) / n;   /* Divisão inteira com arredondamento para cima (teto) */

    /* ===== 2) MÉDIA ANUAL DE CADA OPERADORA ===== */
    int mediaOp[OPS];                            /* Vetor que guardará a média de cada operadora */
    for (i = 0; i < OPS; i++) {                  /* Percorre as operadoras */
        mediaOp[i] = (totalOp[i] + MESES - 1) / MESES; /* Total anual / 12, arredondado para cima */
    }

    /* ===== 3) MÊS COM MAIOR VENDA CONJUNTA ===== */
    int melhorMes = 0;                           /* Guarda o ÍNDICE do melhor mês; começa supondo que é jan */
    for (j = 1; j < MESES; j++) {                /* Compara a partir de fev (índice 1) até dez */
        if (totalMes[j] > totalMes[melhorMes]) { /* Se o mês j vendeu mais que o melhor até agora... */
            melhorMes = j;                       /* ...ele passa a ser o novo melhor mês */
        }
    }

    /* ===== 4) OPERADORA COM MAIOR TOTAL ANUAL ===== */
    int melhorOp = 0;                            /* Guarda o ÍNDICE da melhor operadora; começa supondo Vivo */
    for (i = 1; i < OPS; i++) {                  /* Compara a partir da Claro (índice 1) até a TIM */
        if (totalOp[i] > totalOp[melhorOp]) {    /* Se a operadora i vendeu mais que a melhor até agora... */
            melhorOp = i;                        /* ...ela passa a ser a nova melhor operadora */
        }
    }

    /* ===== RELATÓRIO ===== */
    printf("RELATORIO ANUAL DE VENDAS\n\n");                  /* Título do relatório */
    printf("Media mensal geral: %d chips\n\n", mediaGeral);   /* Mostra a média geral calculada */

    for (i = 0; i < OPS; i++) {                               /* Percorre as operadoras */
        printf("Media da %s: %d chips\n", operadoras[i], mediaOp[i]); /* Mostra nome e média de cada uma */
    }

    printf("\nMes com maior media de vendas: %s - %d chips\n",
           meses[melhorMes], totalMes[melhorMes]);            /* Mostra o nome do melhor mês e sua soma */
    printf("Operadora com maior venda anual: %s - %d chips\n",
           operadoras[melhorOp], mediaOp[melhorOp]);          /* Mostra a melhor operadora e sua média */

    return 0;                                    /* Encerra o programa informando que terminou sem erros */
}                                                /* Fim da função main */
