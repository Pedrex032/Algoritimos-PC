#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define TAM 6 //define um tamnho como constante, sempre em maiusculo

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, abaixoMed=0;
    float salario[TAM], media, soma=0, maiorSalar;

    for(i=0; i<TAM; i++){
        printf("Digite o salário do %d funcionário ", (i+1));
        scanf("%f", &salario[i]);

        soma += salario[i];
    }

    media = soma/TAM;
    maiorSalar = salario[0];

    for(i=0; i<TAM; i++){
        if(salario[i]>maiorSalar){
            maiorSalar = salario[i];
        }
        if(salario[i]<media){
            abaixoMed++;
        }
    }

    printf("A média dos salários é: %.2f\n", media);
    printf("O maior salário é: %.2f\n", maiorSalar);
    printf("Há %d salários abaixo da média\n", abaixoMed);

    return 0;

}
