#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float media, freq;

    printf("Qual a média final do aluno? ");
    scanf("%f", &media);
    printf("Qual o porcentua de frequencia do aluno? ");
    scanf("%f", &freq);

    if(freq<70){
        printf("O aluno foi reprovado por falta\n");
    }else if(media<6){
        printf("O aluno foi reprovado por nota\n");
    }else{
        printf("O aluno foi aprovado\n");
    }

    return 0;
}
