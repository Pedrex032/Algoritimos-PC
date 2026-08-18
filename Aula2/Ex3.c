#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int semanas;
    float meses;

    printf("Qual a quantidade de semanas de gestação? ");
    scanf("%d", &semanas);

    meses = (float) (semanas*7)/30.0;

    printf("Tempo de gestação aprox.: %.1f meses", meses);

    return 0;
}
