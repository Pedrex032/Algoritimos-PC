#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

float calcular_area(float largura, float comprimento)
{
    return largura*comprimento;
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    float largura, comprimento;
    char resposta;

    do{
        printf("Digite a largura (m) ");
        scanf("%f", &largura);

        printf("Digite o comprimento(m) ");
        scanf("%f", &comprimento);

        printf("Area: %.1f m²\n", calcular_area(largura, comprimento));

        printf("Deseja calcular outra área? ");
        scanf(" %c", &resposta);

    }while(resposta=='s' || resposta=='S');
}
