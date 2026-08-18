#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int nota1, nota2;
    float media;

    printf("digite a primeira nota ");
    scanf("%d", &nota1);

    printf("digite a segunda nota ");
    scanf("%d", &nota2);

    media = (float) (nota1+nota2)/2;

    printf("a média do aluno é %.1f", media);

    return 0;
}
