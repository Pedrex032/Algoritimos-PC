#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int quantVal, i, positivos=0, negativos=0;
    double valorNum, maior;

    printf("Digite a quantidade de valores ");
    scanf("%d", &quantVal);

    if(quantVal <= 0){
        printf("Quantidade inválida!\n");
        return 1;
    }

    for(i=0; i<quantVal; i++){

        //printf("%d", i);

        printf("\nDigite o valor %d: ", (i+1));
        scanf("%lf", &valorNum);

        if(valorNum>0){

            positivos++;
            //printf("\nPOSITIVO DETECTADO, valor de positivos: %d\n", positivos);

        }else if(valorNum<0){

            negativos++;
            //printf("\nNEGATIVO DETECTADO, valor de negativos: %d\n", negativos);

        }

        if(i==0 || valorNum > maior){

            maior = valorNum;
            //printf("\nO maior valor agora é %lf\n", maior);

        }
    }

    printf("\nQuantidade de valores positivos: %d\n", positivos);
    printf("Quantidade de valores negativos: %d\n", negativos);
    printf("Maior valor registrado: %.0f\n", maior);

    return 0;

}
