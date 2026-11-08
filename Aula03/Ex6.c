#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float largArea, compArea, valor, areaTotal, qntCaixas, preco;

    printf("qual a largura da área em metros? ");
    scanf("%f", &largArea);

    printf("qual a comprimento da área em metros? ");
    scanf("%f", &compArea);

    printf("qual o valor de cada caixa? ");
    scanf("%f", &valor);

    areaTotal = largArea*compArea;
    qntCaixas = ceil(areaTotal/2.5); // cada caixa cobre 2.5m²
    preco = valor*qntCaixas;

    printf("area total a ser revestida: %.2f", areaTotal); printf("m² \n");
    printf("a quantidade de caixas a serem usada é: %.f\n", qntCaixas);
    printf("o custo total será: %.2f", preco); printf("R$.\n");

    return 0;
}
