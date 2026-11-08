#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float coord1x, coord1y, coord2x, coord2y;

    printf("Digite o a coordenada X do primeiro ponto ");
    scanf("%f", &coord1x);

    printf("Digite o a coordenada y do primeiro ponto ");
    scanf("%f", &coord1y);

    ////////////////////////////////////////////////////

    printf("Digite o a coordenada X do segundo ponto ");
    scanf("%f", &coord2x);

    printf("Digite o a coordenada y do segundo ponto ");
    scanf("%f", &coord2y);

    float distEuc;

    distEuc = sqrt(pow(coord2x - coord1x, 2) + pow(coord2y - coord1y, 2));

    printf("A distância entre os pontos é %.2f\n", distEuc);

    return 0;
}
