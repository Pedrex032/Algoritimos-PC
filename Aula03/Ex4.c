#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int horas, watts;
    float consumo;

    printf("Digite a potencia em watts do equipamento ");
    scanf("%d", &watts);

    printf("Digite as horas de uso do equipamento ");
    scanf("%d", &horas);

    //consumo = (potencia*horas_dia*30)/1000;

    consumo = ((float)watts*horas*30)/1000;

    printf("O consumo mensal do equipamento é: %.2f", consumo); printf(" kwh"); // colocar %.""2""f para o numero não ser arredondado

    return 0;
}
