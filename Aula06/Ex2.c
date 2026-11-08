#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i;
    float nota, soma=0, media, maiorNota=0;

    for(i=0; i<5; i++){

        printf("\nDigite a nota do %dº estudante ", (i+1));
        scanf("%f", &nota);

        soma += nota;

        if(nota>maiorNota){
            maiorNota = nota;
        }

        //printf("\n %.1f", nota);
    }

    media = soma/i;
    printf("\nMédia da turma %.1f", media);
    printf("\nMaior nota: %.1f", maiorNota);

    return 0;

}
