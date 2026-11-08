#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define TAM 8 //define um tamnho como constante, sempre em maiusculo

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, valor[TAM], soma, media, acimaMed=0;

    for(i=0; i<TAM; i++){
        printf("Digite o %d valor ", (i+1));
        scanf("%d", &valor[i]);

        soma += valor[i];
    }

    media = soma/TAM;

    for(i=0; i<TAM; i++){
        if(valor[i] > media){
            acimaMed++;
        }
    }

    printf("A média dos valores é: %d\n", media);
    printf("Há: %d de valores acima da média\n", acimaMed);

    return 0;

}
