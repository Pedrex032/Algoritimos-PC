#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float peso, altura;

    printf("Qual o seu peso em kg? ");
    scanf("%f", &peso);
    printf("Qual a sua altura em e metros? ");
    scanf("%f", &altura);

    float IMC;

    //printf("IMC: ");
    //scanf("%f", &IMC);

    IMC = peso / pow(altura, 2);

    //printf("IMC: %.2f\n\n", IMC);

    if(IMC<=20){
        printf("Você está abaixo do peso.\n");
    }else if(IMC<25){
        printf("Seu peso está normal.\n");
    }else if(IMC<30){
        printf("Você está com sobre peso.\n");
    }else if(IMC<40){
        printf("Você está em estado de obesidade.\n");
    }else{
        printf("Você está com obesidade morbida.\n");
    }

    return 0;
}
