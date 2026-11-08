#include<stdio.h>
#include<locale.h>
#include<math.h>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    char linha[100];

    FILE *arquivo = fopen("tabuada.txt", "r");

    if(arquivo==NULL){
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 1;
    }

    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        printf("%s", linha);
    }

    return 0;

}
