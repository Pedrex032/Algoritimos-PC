#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, cpf;
    float preco=1, total_val=0;

    printf("Digite seu CPF ");
    scanf("%d", &cpf);

    while(preco>0){

        printf("\nPreço%d R$: ", i);
        scanf("%f", &preco);

        total_val += preco;

    }

    printf("CPF: %d\n", cpf);
    printf("O valor total da compra é R$:%.2f\n", total_val);

    return 0;

}
