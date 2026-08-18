#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int quantidade;
    float precoUnitario, valorFinal;

    printf("Qual a quantidade de cafés? ");
    scanf("%d", &quantidade);

    printf("Qual o preço unitário? R$");
    scanf("%f", &precoUnitario);

    valorFinal = quantidade*precoUnitario;

    printf("Total a pagar é: R$%.2f", valorFinal);

    return 0;
}
