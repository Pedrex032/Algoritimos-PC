#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

float media_Nota(float nota1, float nota2)
{
    return (nota1+nota2)/2;
}

void exibir_resultado(float nota1, float nota2)
{
    float media = media_Nota(nota1, nota2);
    printf("A media do aluno é: %.1f\n", media);

    if(media>=7){
            printf("Situação: Aprovado\n");
    }else{
            printf("Situação: Reprovado\n");
    }
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    float nota1, nota2;
    char resposta;

    do{
        printf("Digite a primeira nota ");
        scanf("%f", &nota1);

        printf("Digite a segunda nota ");
        scanf("%f", &nota2);

        exibir_resultado(nota1, nota2);

        printf("Deseja continuar? ");
        scanf(" %c", &resposta);

    }while(resposta=='s' || resposta=='S');
}
