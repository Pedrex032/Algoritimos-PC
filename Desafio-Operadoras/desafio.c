#include <stdio.h>

#define OPS 3
#define MESES 12

int main(void) {
    const char *meses[] = {"jan", "fev", "mar", "abr", "mai", "jun",
                           "jul", "ago", "set", "out", "nov", "dez"};
    const char *operadoras[] = {"Vivo", "Claro", "TIM"};

    int vendas[OPS][MESES];

    int i, j;
    int totalGeral = 0;
    int totalOp[OPS];
    int totalMes[MESES];

    //ENTRADAS
    printf("=== VENDA DE CHIPS ===\n");
    printf("Informe a quantidade de chips vendidos.\n\n");

    for (i = 0; i < OPS; i++) {
        printf("Operadora %s:\n", operadoras[i]);
        for (j = 0; j < MESES; j++) {
            do {
                printf("%s: ", meses[j]);
                scanf("%d", &vendas[i][j]);
                if (vendas[i][j] < 0) {
                    printf("Valor invalido. Digite um numero maior ou igual a 0.\n");
                }
            } while (vendas[i][j] < 0);
        }
        printf("\n");
    }

    //ZERARAGEM DOS VETORES
    for (i = 0; i < OPS; i++)   totalOp[i] = 0;
    for (j = 0; j < MESES; j++) totalMes[j] = 0;

    //SOMAS
    for (i = 0; i < OPS; i++) {
        for (j = 0; j < MESES; j++) {
            totalOp[i]  += vendas[i][j];
            totalMes[j] += vendas[i][j];
            totalGeral  += vendas[i][j];
        }
    }

    //MEDIA MENSAL
    int n = OPS * MESES;
    int mediaGeral = (totalGeral + n - 1) / n;

    //MEDIA ANUAL
    int mediaOp[OPS];
    for (i = 0; i < OPS; i++) {
        mediaOp[i] = (totalOp[i] + MESES - 1) / MESES;
    }

    //MES COM MAIS VENDAS
    int melhorMes = 0;
    for (j = 1; j < MESES; j++) {
        if (totalMes[j] > totalMes[melhorMes]) {
            melhorMes = j;
        }
    }

    //OPERADORA COM MAIOR ANUAL
    int melhorOp = 0;
    for (i = 1; i < OPS; i++) {
        if (totalOp[i] > totalOp[melhorOp]) {
            melhorOp = i;
        }
    }

    //SAÍDA
    printf("RELATORIO ANUAL DE VENDAS\n\n");
    printf("Media mensal geral: %d chips\n\n", mediaGeral);

    for (i = 0; i < OPS; i++) {
        printf("Media da %s: %d chips\n", operadoras[i], mediaOp[i]);
    }

    printf("\nMes com maior media de vendas: %s - %d chips\n",
           meses[melhorMes], totalMes[melhorMes]);
    printf("Operadora com maior venda anual: %s - %d chips\n",
           operadoras[melhorOp], mediaOp[melhorOp]);

    return 0;
}
