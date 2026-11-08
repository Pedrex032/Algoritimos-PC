#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

typedef struct aluno
{
    char nome[50];
    int rgm;
    float media;
} Aluno;

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    Aluno aluno1;

    aluno1.rgm = 12345;
    aluno1.media = 8.5;

    printf("RGM: %d\n", aluno1.rgm);
    printf("Média: %.1f\n", aluno1.media);

    return 0;
}
