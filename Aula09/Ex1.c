#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_CTYPE, "Portuguese");

    FILE *arquivo;
    int i, num;

    arquivo = fopen("tabuada.txt", "a");

    if (arquivo == NULL) {
        printf("\nERRO AO CRIAR ARQUIVO\n");
        return 1;
    }

    printf("Digite um número inteiro: ");
    scanf("%d", &num);

    printf("Tabuada do %d\n", num);
    fprintf(arquivo, "Tabuada do %d\n", num);

    for (i = 1; i <= 10; i++) {
        printf("%d * %d = %d\n", num, i, num * i);
        fprintf(arquivo, "%d * %d = %d\n", num, i, num * i);
    }

    printf("\nArquivo criado com sucesso\n");
    fprintf(arquivo, "\n");
    fclose(arquivo);

    return 0;
}
