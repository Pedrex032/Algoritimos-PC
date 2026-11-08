#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

float calcularArea(float base, float altura)
{
    return base * altura;
}

int main() //int main é uma função e return é seu resultado geralmente retorna 0
{

    setlocale(LC_CTYPE, "Portuguese");

    float base, altura, area;

    base = 5;
    altura = 6;
    area = base*altura;

    printf("A area do retángulo é %.1f cm2\n", calcularArea(base, altura));

    printf("A area do retángulo é %.1f cm2\n", calcularArea(5, 7.8));
    printf("A area do retángulo é %.1f cm2\n", calcularArea(3, 8));
    printf("A area do retángulo é %.1f cm2\n", calcularArea(8, 9));

    return 0;

}
