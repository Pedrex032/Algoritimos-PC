#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int rgm = 12345529483, idade;
    float media = 7.59234;

    //printf("Dados do aluno\n");
    //printf("RGM: %d\n", rgm);
    //printf("Média: %.2f\n\n", media);

    printf("Digite sua didade: ");
    scanf("%d", &idade);
    printf("Sua idade é: %d\n", idade);

    //system("pause");
    return 0;
}
