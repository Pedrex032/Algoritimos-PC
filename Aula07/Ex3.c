#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, aprovados=0;
    float nota;

    for(i=1; i<=10; i++){

        printf("\nDigite a nota do %dº aluno ", i);
        scanf("%f", &nota);

        if(nota >= 6.0){
            aprovados++;
        }

    }

    printf("\nA quantidade de alunos aprovados são %d\n", aprovados);

    return 0;

}
