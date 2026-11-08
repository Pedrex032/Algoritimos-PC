#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float peso, altura, imc;

    printf("qual o peso da pessoa em Kg? ");
    scanf("%f", &peso);

    printf("qual a altura da pessoa em metros? ");
    scanf("%f", &altura);

    imc = peso/(altura*altura);

    printf("O indice de massa corporal é %.2f", imc); printf(" kg/m²");

    return 0;
}
