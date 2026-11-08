#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define TAM 6 //define um tamnho como constante, sempre em maiusculo

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i;
    float salario[TAM];

    for(i=0; i<TAM; i++){
        printf("Digite o salário do funcionário %d: ", (i+1));
        scanf("%f", &salario[i]);
    }
    for(i=0; i<TAM; i++){
        printf("Salário do funcionário %d R$: %.2f\n", (i+1), salario[i]);
    }

    return 0;

}
