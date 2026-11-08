#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define LIN 3
#define COL 4

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, j, totalVal, totalGeral=0;
    int valores[LIN][COL];

    //const char *produtos[]{"café", "coxinha", "bolo",}

    for(i=0; i<LIN; i++){
        for(j=0; j<COL; j++){

            printf("Digite a qte do produto %d no dia %d ", (i+1), (j+1));
            scanf("%d", &valores[i][j]);
        }
        printf("\n");
    }

    printf("Relatório:\n");

    for(i=0; i<LIN; i++){
        totalVal = 0;
        for(j=0; j<COL; j++){
            totalVal += valores[i][j];
        }
        totalGeral += totalVal;

        printf("Produdo %d: %d unidades\n", (i+1), totalVal);
    }

    printf("Total Geral: %d unidades.\n", totalGeral);

    return 0;

}
