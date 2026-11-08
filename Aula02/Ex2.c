#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float comprimento, largura, perimetro, area;

    printf("Qual é o comprimento do jardim (em m)? ");
    scanf("%f", &comprimento);

    printf("Qual é a largura do jardim (em m)? ");
    scanf("%f", &largura);

    perimetro = 2*(comprimento+largura);
    area = comprimento*largura;

    printf("O perimetro do jardim é: %.2fm\n", perimetro);
    printf("A area do jardim é: %.2fm2\n", area);

    return 0;
}
