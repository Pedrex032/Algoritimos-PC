#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float val1, val2, val3, val4;

    printf("Digite o primeiro valor ");
    scanf("%f", &val1);

    printf("Digite o segundo valor ");
    scanf("%f", &val2);

    printf("Digite o terceiro valor ");
    scanf("%f", &val3);

    printf("Digite o quarto valor ");
    scanf("%f", &val4);

    float media;

    media = (val1+val2+val3+val4)/4;

    printf("A média aritimética dos valores é %.2f", media);

    return 0;
}
