#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float val1, val2, val3;

    printf("Digite o primeiro valor ");
    scanf("%f", &val1);

    printf("Digite o segundo valor ");
    scanf("%f", &val2);

    printf("Digite o terceiro valor ");
    scanf("%f", &val3);

    float mediaPon;

    mediaPon = (val1*1+val2*2+val3*4)/7.00;

    printf("A média ponderada é %.2f", mediaPon);

    return 0;
}
