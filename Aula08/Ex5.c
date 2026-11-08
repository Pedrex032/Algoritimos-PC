#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define NOT 4
#define ALU 3

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, j, acheiAlun=1;
    float notas[ALU][NOT], soma, media, maiorMedia=0;

    for(i=0; i<ALU; i++){
        for(j=0; j<NOT; j++){
            printf("Digite a %dª nota do %d° estudante ", (j+1), (i+1));
            scanf("%f", &notas[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<ALU; i++){

        soma = 0;
        for(j=0; j<NOT; j++){
            soma += notas[i][j];
        }

        media = soma/NOT;

        printf("A média do %d° aluno é: %.2f\n", (i+1), media);

        if(media>maiorMedia){
            maiorMedia = media;
            acheiAlun = i;
        }

    }

    //printf("%.2f\n", soma);

    printf("A maior média foi %.2f do aluno: %d\n", maiorMedia, (acheiAlun+1));

    return 0;

}
