#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float nota1, nota2;

    printf("Digite a primeira nota ");
    scanf("%f", &nota1);
    printf("Digite a primeira nota ");
    scanf("%f", &nota2);

    float media;
    media = (nota1*nota2)/2;

    if(media>=6){
        printf("Parabéns, você foi aprovado com a nota %.2f\n", media);
    }else if(media>=3){
        printf("Você está de recuperação e terá de fazer um exame. Sua nota %.2f.", media);
    }else{
        printf("Você reprovou. Estude mais! Sua nota %.2f", media);
    }

    return 0;
}
