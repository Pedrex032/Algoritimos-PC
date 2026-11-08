#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define QTD 10 // constante da quantidade de alunos

typedef struct // struct de aluno com typedef Aluno
{
    int rgm;
    char nome[50];
    float nota1, nota2, media;
}Aluno;

// prototipos das funções:
void cadastrar_aluno(Aluno *alunos, int *quantidade);
void consultar_aluno(Aluno alunos[], int quantidade, int qual_rgm);
void listar_alunos(Aluno alunos[], int quantidade);
void calcular_media(Aluno *alunos);
int rgm_existe(Aluno alunos[], int quantidade, int rgm);

int main()
{

    setlocale(LC_CTYPE, "");

    int opcao=0, quantidade=0, qual_rgm;

    Aluno alunos[QTD];

    do{ // laço de repetição principal

        printf("===== SISTEMA ACADÊMICO =====\n\n");

        printf(" 1- Cadastrar aluno\n");
        printf(" 2- Consultar aluno (rgm)\n");
        printf(" 3- Listar alunos\n");
        printf(" 4- sair\n\n");

        printf("Escolha uma opção ");

        if (scanf("%d", &opcao) != 1) // scanf de opção com validação para evitar loops infinitos caso seja inserido um char
        {
            while (getchar() != '\n');   // descarta tudo até o Enter
            opcao = 0;                   // valor inválido: cai no default do switch
        }

        system("cls");

        switch(opcao){ // switch com opções:

            case 1:

                cadastrar_aluno(alunos, &quantidade);

                break;

            case 2:

                printf("===== CONSULTA DE ALUNO =====\n\n");

                printf("Escreva o RGM do aluno para consultar ");
                scanf("%d", &qual_rgm);

                consultar_aluno(alunos, quantidade, qual_rgm);

                system("pause");
                system("cls");

                break;

            case 3:

                listar_alunos(alunos, quantidade);

                system("pause");
                system("cls");

                break;

            case 4:

                printf("\nVocê escolheu Sair.\n");
                break;

            default:

                printf("\nOPÇÃO INVALIDA! escolha uma das opções:\n\n");
        }

    }while(opcao != 4);// o loop para caso opcao seja igual a 4

    return 0;

}

void cadastrar_aluno(Aluno *alunos, int *quantidade)
{
    int novo_rgm;

    system("cls");

    if(*quantidade >= QTD){
        printf("Você alcançou o limite de alunos do sistema!\n\n");
    }else{

        printf("===== CADASTRO DE ALUNO =====\n\n");

        printf(" RGM ");
        scanf("%d", &novo_rgm);

        if(rgm_existe(alunos, *quantidade, novo_rgm)){
            printf("\nRGM já cadastrado!\n\n");
            system("pause");
            system("cls");
            return;// sai sem gravar nada
        }

        alunos[*quantidade].rgm = novo_rgm;// só grava depois de validar

        printf(" Nome do aluno ");
        scanf("%s", alunos[*quantidade].nome);
        printf(" 1º Nota ");
        scanf("%f", &alunos[*quantidade].nota1);
        printf(" 2º Nota ");
        scanf("%f", &alunos[*quantidade].nota2);

        (*quantidade)++;

        system("cls");
        printf(" \n%dº Aluno registrado\n\n ", *quantidade);
    }
}

void consultar_aluno(Aluno alunos[], int quantidade, int qual_rgm) //função de procura de aluno
{
    int encontrei=0;// validador recebe valor 1 caso o aluno seja encontrado

    for(int i=0; i < quantidade; i++){// loop de repetição que para no ultimo aluno registrado

        if(alunos[i].rgm == qual_rgm){ // caso o vetor de alunos tenha o rgm igual a variável qual_rgm, significa que o aluno foi encontrado

            encontrei = 1;// validador recebe valor 1 pois o aluno foi encontrado

            printf("\nAluno encontrado:\n\n");

            printf(" Nome: %s\n", alunos[i].nome);
            printf(" RGM: %d\n", alunos[i].rgm);
            printf(" Nota1: %.1f\n", alunos[i].nota1);
            printf(" Nota2: %.1f\n", alunos[i].nota2);
            calcular_media(&alunos[i]);
            printf(" Media: %.1f\n\n", alunos[i].media);

            break; // para o loop
        }
    }

    if(encontrei==0){ // usa o validador para imprimir o aluno não encontrado
        printf("\nAluno não encontrado\n\n");
    }
}

void listar_alunos(Aluno alunos[], int quantidade) // função de listagem de alunos
{
    for(int i=0; i < quantidade; i++){

        printf(" Nome: %s\n", alunos[i].nome);
        printf(" RGM: %d\n", alunos[i].rgm);
        printf(" Nota1: %.1f\n", alunos[i].nota1);
        printf(" Nota2: %.1f\n", alunos[i].nota2);
        calcular_media(&alunos[i]);
        printf(" Media: %.1f\n\n", alunos[i].media);
    }

    if(quantidade == 0){ // caso não haja alunos printa aviso
        printf("Não há alunos registrados.\n\n");
    }
}

void calcular_media(Aluno *alunos)// função de calcular media
{
    alunos->media = (alunos->nota1 + alunos->nota2)/2;
}

int rgm_existe(Aluno alunos[], int quantidade, int rgm)
{
    for(int i=0; i < quantidade; i++){

        if(alunos[i].rgm == rgm){
            return 1;// achou: já existe
        }
    }

    return 0;// terminou o laço sem achar: não existe
}









