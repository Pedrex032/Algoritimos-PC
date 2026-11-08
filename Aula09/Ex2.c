#include<stdio.h>
#include<locale.h>
#define DIAS 3

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    FILE *arquivo;

    int i;
    float consumo[DIAS];
    char diasSemana[DIAS];

    arquivo = fopen("consumo.txt", "a");

    if(arquivo==NULL){
        printf("ERRO AO CRIAR ARQUIVO");
        return 1;
    }

    for(i=0; i<DIAS; i++){

        printf("Digite o dia da semana ");
        scanf("%3s", diasSemana);

        printf("Dia %s\n", diasSemana);
        printf("Consumo: ");
        scanf("%f", &consumo[i]);

        fprintf(arquivo, "%s: %2.f\n", diasSemana, consumo[i]);
    }

    fprintf(arquivo, "\n");
    fclose(arquivo);
    return 0;

}
