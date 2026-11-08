#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int num, somaImpar=0;

    do{

        printf("\nDigite um número inteiro ");
        scanf("%d", &num);


        if(num%2 !=0){

            somaImpar += num;

            printf("IMPAR DETECTADO!: %d\n", num);
            printf("Valor atual dos impar: %d\n", somaImpar);
        }
    }while(num>0);

    printf("\n\nSoma dos números impar: %d\n\n", somaImpar);

    return 0;

}
