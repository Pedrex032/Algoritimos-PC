#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_CTYPE, "Portuguese");

    char venda[3];
    float valor;
    int contador = 0;

    FILE *arquivo = fopen("vendas.txt", "r");

    if (arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 1;
    }

    while (fscanf(arquivo, "%3s %f", venda, &valor) == EOF) {
        contador++;

        printf("%.2f\n", venda);
    }

    printf("Quantidade de vendas: %d\n", contador);

    fclose(arquivo);
    return 0;
}
