#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

typedef struct aluno
{
    int rgm;
    float nota1, nota2, media;

} Aluno;

void calcualar_media(Aluno *aluno)
{
    aluno->media = (aluno->nota1 + aluno->nota2)/2;
}

int main()
{
    setlocale(LC_CTYPE, "Portuguese");

    Aluno aluno1;

    printf("RGM ");
    scanf("%d", &aluno1.rgm);

    printf("Nota 1 ");
    scanf("%f", &aluno1.nota1);

    printf("Nota 2 ");
    scanf("%f", &aluno1.nota2);

    printf("RGM: %d\n", aluno1.rgm);

    calcualar_media(&aluno1);

    printf("Media: %.2f\n", aluno1.media);

    return 0;
}
