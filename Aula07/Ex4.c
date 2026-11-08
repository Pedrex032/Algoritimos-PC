#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, inferiorTemp=0;
    char municipio[50];
    float temperatura, somaTemp=0, media;

    for(i=0; i<5; i++){

        printf("\nDigite o nome do %dº município ", (i+1));
        scanf("%49s", municipio);

        printf("\nDigite temperatura média do %dº município ", (i+1));
        scanf("%f", &temperatura);

        if(temperatura < 10.0){
            inferiorTemp++;
        }

        somaTemp += temperatura;

    }

    media = (somaTemp/5);

    printf("\nA temperatura média da região é: %.1fºc", media);
    printf("\nA quantidade de municípios com a temperatura inferior a 10ºc é: %d\n", inferiorTemp);

    return 0;

}
