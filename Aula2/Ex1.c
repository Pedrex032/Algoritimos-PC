#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float Raio, perimetro;

    printf("Qual a média do raio (em cm)? ");
    scanf("%f", &Raio);

    perimetro = 2*3.14159*Raio;

    printf("O perimetro da circuferencia é: %fcm", perimetro);

    return 0;
}
