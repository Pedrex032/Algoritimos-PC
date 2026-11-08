#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int valA, valB, valC;

    printf("Digite o valor de a: ");
    scanf("%d", &valA);
    printf("Digite o valor de b: ");
    scanf("%d", &valB);
    printf("Digite o valor de c: ");
    scanf("%d", &valC);

    float X1, X2, Delta;

    Delta = (float)(valB * valB)-(4*valA*valC);

    if(Delta>=0){
        X1 = (float)(-valB - sqrt(Delta)) / (2 * valA);
        X2 = (float)(-valB + sqrt(Delta)) / (2 * valA);

        printf("Valor de Delta: %.f\n\n", Delta);
        printf("Raizes da equação:\n");
        printf("X1 = %.1f\n", X1);
        printf("X2 = %.1f\n", X2);
    }else{
        printf("Não há raizes reais.");
    }

    return 0;
}
