#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i;
    double preco, valTotal=0;

    for(i=1; i<=7; i++){

        printf("\nDigite o valor total de vendas do dia %d R$: ", i);
        scanf("%lf", &preco);

        valTotal += preco;

    }

    printf("\nO total de lucro da semana é R$%.2f\n", valTotal);

    return 0;

}
