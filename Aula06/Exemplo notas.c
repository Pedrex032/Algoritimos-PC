
#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i;
    float nota, soma=0, media;

    for(i=0; i<3; i++){

        do{
            printf("\nDigite a nota do %dº aluno (0-10): ", (i+1));
            scanf("%f", &nota);

            if(nota<0 || nota>10){
                printf("INVÁLIDO\n");
            }else{
                soma += nota;
            }

        }while(nota<0 || nota>10);

    }

    media=soma/3;
    printf("\nA média das notas é %.1f\n", media);

    return 0;

}
