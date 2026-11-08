#include<stdio.h>
#include<locale.h>
#define NOTAS 3

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    FILE *arquivo;

    int i;
    float notas[NOTAS];
    char RGM[3];

    arquivo = fopen("notas.txt", "w");

    if(arquivo==NULL){
        printf("ERRO AO CRIAR ARQUIVO");
        return 1;
    }

    for(i=0; i<NOTAS; i++){

        printf("Digite o RGM do aluno ");
        scanf("%9s", RGM);

        printf("Aluno %s\n", RGM);
        printf("nota ");
        scanf("%f", &notas[i]);

        fprintf(arquivo, "%s %2.f\n", RGM, notas[i]);
    }

    fprintf(arquivo, "\n");
    fclose(arquivo);
    return 0;

}
