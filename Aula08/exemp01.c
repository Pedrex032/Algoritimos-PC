#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define TAM 5 //define um tamnho como constante, sempre em maiusculo

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    /*Estruturas de dados em C
      Estruturas Homogéneas*/

    float salarios[TAM], soma=0, media, maiorSalar;
    int i=0, contador=0, acheiMaior;

    for(i=0; i<TAM; i++){
        printf("Digite o salário do %d funcionário ", (i+1));
        scanf("%f", &salarios[i]);
    }

    for(i=0; i<TAM; i++){
        printf("Salário do funcionário %d: %.2f\n", (i+1), salarios[i]);

        soma += salarios[i];
    }

    media = soma/TAM;
    maiorSalar = salarios[0];
    acheiMaior = 1; //define que o primeiro salário é o maior caso nenhum outro seja.

    for(i=0; i<TAM; i++){
        if(salarios[i] > media){
            contador++;
        }
        if(salarios[i]>maiorSalar){
            maiorSalar = salarios[i];
            acheiMaior = (i+1);
        }
    }

    printf("A média dos salários é %.2f\n", media);
    printf("Há %d de salários acima da média\n", contador);
    printf("O maior salário é RS: %.2f do funcionário %d\n", maiorSalar, acheiMaior);

    return 0;

}
