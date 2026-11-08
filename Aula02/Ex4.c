#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_CTYPE, "");

    float massaCorporal, aguaReco;

    printf("Digite a massa corporal (em kg) ");
    scanf("%f", &massaCorporal);

    aguaReco = 35*massaCorporal/1000;

    printf("A quantidade aproximada de água recomendada por dia é %.1f litros\n", aguaReco);

    return 0;
}
