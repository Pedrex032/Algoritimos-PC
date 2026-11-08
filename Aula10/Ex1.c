#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

float calcular_frete(float peso)
{
    return peso*4.50;
}

int main() //int main é uma função e return é seu resultado geralmente retorna 0
{

    setlocale(LC_CTYPE, "Portuguese");

    float peso;
    char resposta;

    do{
        printf("\nDigite o peso (kg) ");
        scanf("%f", &peso);

        printf("Valor do frete: R$ %.2f\n", calcular_frete(peso));
        printf("Deseja continuar? ");

        scanf(" %c", &resposta);
    }while(resposta=='s' || resposta=='S');
}
