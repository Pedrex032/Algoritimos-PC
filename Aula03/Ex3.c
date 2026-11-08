#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int num1, num2, soma, subt, mult;

    printf("Escreva o primeiro número ");
    scanf("%d", &num1);

    printf("Escreva o segundo número ");
    scanf("%d", &num2);

    soma = num1+num2;
    subt = num1-num2;
    mult = num1*num2;

    printf("Soma: %.d\n", soma);
    printf("Subtração: %.d\n", subt);
    printf("Divisão: %.d\n", mult);

    return 0;
}
