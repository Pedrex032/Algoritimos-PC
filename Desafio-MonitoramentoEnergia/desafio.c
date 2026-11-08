#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// definindo constantes
#define DIAS 7
#define LABS 4
#define LIMITE 100

// prototipos das funções:
void cadastrar_consumo(float consumo[][DIAS], const char *dias[], const char *labs[]);
float consumo_geral(float consumo[][DIAS]);
float media_laboratorios(float consumo[][DIAS], int laboratorio);
float dia_maior_consumo(float consumo[][DIAS], int *dia);
float lab_maior_consumo(float consumo[][DIAS], int *lab);
int acima_limite(float consumo[][DIAS]);

int main()
{
    setlocale(LC_CTYPE, "");

    // declaração de variáveis

    float consumo[LABS][DIAS] /*= {// remover essas bagaças depois
        {80, 90, 95, 110, 120, 100, 85},
        {75, 85, 90, 105, 115, 95, 80},
        {100, 110, 120, 130, 125, 115, 105},
        {70, 80, 85, 90, 100, 95, 75}
    }*/;

    const char *dias[] =
    {
        "seg", "ter", "qua", "qui",
        "sex", "sab", "dom"
    };

    const char *labs[] =
    {
        "lab A", "lab B", "lab C", "lab D"
    };

    float total, media, maiorDia, maiorLab;
    int dia, lab;

    // chamada de funções
    cadastrar_consumo(consumo, dias, labs);

    printf("===== RELATORIO DE CONSUMO =====\n\n");

    total = consumo_geral(consumo);
    printf("Consumo total geral: %.2f kwh\n\n", total);

    for(int i=0; i < LABS; i++){
        media = media_laboratorios(consumo, i);
        printf("Média de consumo do %s: %.2f kwh\n", labs[i], media);
    }

    maiorDia = dia_maior_consumo(consumo, &dia);
    printf("\nDia com maior consumo total:\n%s: %.2f kwh\n", dias[dia], maiorDia);

    maiorLab = lab_maior_consumo(consumo, &lab);
    printf("\nLaboratório com maior consumo total:\n%s: %.2f kwh\n", labs[lab], maiorLab);

    printf("\nRegistros acima do limite: %d\n", acima_limite(consumo));

    return 0;
}
// funções:

// função de cadastro de consumos da semana
void cadastrar_consumo(float consumo[][DIAS], const char *dias[], const char *labs[])
{
    for(int i=0; i < LABS; i++){ // i = laboratório (linha)

        printf("%s\n", labs[i]);

        for(int j=0; j < DIAS; j++){ // j = dia (coluna)

            printf("consumo %s: ", dias[j]);
            scanf("%f", &consumo[i][j]);
        }
        system("cls");
    }
}

// função de consumo total geral
float consumo_geral(float consumo[][DIAS])
{
    float adicionador=0;

    for(int i=0; i < LABS; i++){ // i = laboratório (linha)

        for(int j=0; j < DIAS; j++){ // j = dia (coluna)

            adicionador += consumo[i][j];
        }
    }
    return adicionador;
}

// função de media de laboratório
float media_laboratorios(float consumo[][DIAS], int laboratorio)
{
    float adicionador2=0;

    for(int j=0; j < DIAS; j++){ // j = dia (coluna)

        adicionador2 += consumo[laboratorio][j];
    }
    return adicionador2/DIAS;
}

// função de procura de dia com maior consumo
float dia_maior_consumo(float consumo[][DIAS], int *dia)
{
    float adicionador3=0;
    float diaMaior=0;
    int qualDia=0;

    for(int i=0; i < DIAS; i++){ // i = dia (coluna)

        for(int j=0; j < LABS; j++){ // j = laboratório (linha)

            adicionador3 += consumo[j][i];
        }
        if(adicionador3>diaMaior){

            diaMaior = adicionador3;
            qualDia = i;
        }
        adicionador3=0;
    }
    *dia = qualDia;     // entrega o índice do dia pelo ponteiro
    return diaMaior;    // devolve o consumo total daquele dia
}

// função de busca de lab com maior consumo, é igual o de dia só trocar os loops de repetição e variáveis
float lab_maior_consumo(float consumo[][DIAS], int *lab)
{
    float adicionador4=0;
    float labMaior=0;
    int qualLab=0;

    for(int i=0; i < LABS; i++){ // i = laboratório (linha)

        for(int j=0; j < DIAS; j++){ // j = dia (coluna)

            adicionador4 += consumo[i][j];
        }
        if(adicionador4>labMaior){

            labMaior = adicionador4;
            qualLab = i;
        }
        adicionador4=0;
    }
    *lab = qualLab;     // entrega o índice do lab pelo ponteiro
    return labMaior;    // devolve o consumo total daquele laboratório
}

//função de contagem de dias acima do limite de consumo
int acima_limite(float consumo[][DIAS])
{
    int acimaLimite=0;

    for(int i=0; i < LABS; i++){ // i = laboratório (linha)

        for(int j=0; j < DIAS; j++){ // j = dia (coluna)

            if(consumo[i][j] > LIMITE){
                acimaLimite++;
            }
        }
    }
    return acimaLimite;
}
