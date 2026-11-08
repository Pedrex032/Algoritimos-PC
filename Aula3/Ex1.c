#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int produtosManha, produtosTarde, total;

    printf("escreva o número de produtos da manhã ");
    scanf("%d", &produtosManha);

    printf("escreva o número de produtos da tarde ");
    scanf("%d", &produtosTarde);

    total = produtosManha+produtosTarde;

    printf("O total de produtos é %.d", total);

    return 0;
}
