#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    char linha[100], diaSemana[4];
    float media, maiorConsumo, soma, consumo;
    int contador=0;

    FILE *arquivo = fopen("consumo.txt", "r");

    if(arquivo==NULL){
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 1;
    }

    while(fscanf(arquivo, "%3s %f", diaSemana, &consumo ) != EOF){
        soma += consumo;
        contador++;
        if(consumo>maiorConsumo){
            maiorConsumo = consumo;
        }
    }

    media = soma/contador;

    printf("Consumo médiio: %.1f\n", media);
    printf("Mior consumo: %.1f\n", maiorConsumo);

    fclose(arquivo);
    return 0;

}
