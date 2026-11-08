#include<stdio.h>
#include<locale.h> //biblioteca de assentos.

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int horas, minutos, minutosTotal;

    // minutosTotal = será calculado o total de min que se passaram des das 0:00 até o horario do inserido pelo usuário

    printf("Escreva as horas ");
    scanf("%d", &horas);

    printf("Escreva os minutos ");
    scanf("%d", &minutos);

    minutosTotal = horas*60+minutos;

    printf("Se passaram %.d", minutosTotal); printf("min desde o início do dia ");

    return 0;
}
