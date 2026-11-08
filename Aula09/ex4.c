#include <stdio.h>
#include <locale.h>

int main() {

    setlocale(LC_CTYPE, "Portuguese");

    char aluno[9];
    float nota, soma = 0, media, maiorNota = 0;
    int contador = 0, aprovados = 0;

    FILE *arquivo = fopen("notas.txt", "r");

    if (arquivo == NULL) {
        printf("ERRO AO ABRIR ARQUIVO\n");
        return 1;
    }

    while (fscanf(arquivo, "%9s %f", aluno, &nota) == EOF) {

        soma += nota;
        contador++;

        if (nota > maiorNota) {
            maiorNota = nota;
        }

        if (nota >= 6.0) {
            aprovados++;
        }
    }

    fclose(arquivo);

    if (contador == 0) {
        printf("Nenhum estudante encontrado no arquivo.\n");
        return 0;
    }

    media = soma / contador;

    printf("Estudantes: %d\n", contador);
    printf("Média da turma: %.2f\n", media);
    printf("Maior nota: %.2f\n", maiorNota);
    printf("Quantidade de alunos aprovados: %d\n", aprovados);

    return 0;
}
