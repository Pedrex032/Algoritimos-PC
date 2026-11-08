#include <stdio.h>
#include<locale.h> //biblioteca de assentos.
#include <math.h>

int main(void)
{

    setlocale(LC_CTYPE, "Portuguese");

    // Entradas
    int qte_participantes, qte_jogadores_por_time, qte_computadores;
    float potencia, duracao, preco_kwh;
    float preco_kit, outros_custos, orcamento;

    // Processamento
    int qte_times, computadores_faltantes;
    float consumo_energia, custo_energia;
    float custo_alimentacao, custo_total;
    float custo_por_participante, saldo;

    // Entrada de dados
    // Solicite ao usuario todos os dados do evento.

    //ints
    /*printf("Qual a quantidade total de participantes? ");
    scanf("%d", &qte_participantes);

    printf("Qual a quantidade de jogadores em cada time? ");
    scanf("%d", &qte_jogadores_por_time);

    printf("Qual a quantidade de computadores disponíveis? ");
    scanf("%d", &qte_computadores);

    //floats:
    printf("Qual a potência média de cada computador, em watts? ");
    scanf("%f", &potencia);

    printf("Qual a duração do evento, em horas? ");
    scanf("%f", &duracao);

    printf("Qual o preço de 1 kWh de energia? ");
    scanf("%f", &preco_kwh);

    printf("Qual o preço de um kit de alimentação por participante? ");
    scanf("%f", &preco_kit);

    printf("Qual o preço de outros custos do evento? ");
    scanf("%f", &outros_custos);

    printf("Qual o orçamento máximo disponível para o evento? ");
    scanf("%f", &orcamento);*/

    qte_participantes = 30;
    qte_jogadores_por_time = 5;
    qte_computadores = 30;
    potencia = 800;
    duracao = 2;
    preco_kwh = 1.2;
    preco_kit = 20000/1000; //20.000
    outros_custos = 150000/1000; //150.000
    orcamento = 100000/100; //100.000

    // Calculos
    // Calcule:
    // - quantidade de times;
    qte_times = ceil((qte_participantes/qte_jogadores_por_time));

    // - consumo de energia;
    consumo_energia = (qte_computadores * potencia * duracao) / 1000;

    // - custo da energia;
    custo_energia = (consumo_energia * preco_kwh);

    // - custo da alimentacao;
    custo_alimentacao = (qte_participantes * preco_kit);

    // - custo total;
    custo_total = (custo_energia + custo_alimentacao + outros_custos);

    // - custo por participante;
    custo_por_participante = (custo_total / qte_participantes);

    // - saldo do orcamento.
    saldo = (orcamento - custo_total);

    // Relatorio geral
    // Exiba participantes e quantidade de times.

    printf("==================== ARENA TECH ====================\n\n");

    printf("Quant. de participantes: %d \n", qte_participantes);
    printf("times necessários: %d \n", qte_times);

    // Analise da infraestrutura
    // Verifique se a quantidade de computadores e suficiente.

    printf("Computadores disponíveis: %d \n", qte_computadores);

    if(qte_participantes <= qte_computadores){
        printf("INFRAESTRUTURA: SUFICIENTE \n\n");
    }else{
        printf("INFRAESTRUTURA: INDISPONÍVEL \n\n");
    }///////////////////////////////////////////////////////////////////////////////////////////////////////////+ quantidade faltante

    // Classificacao do consumo de energia

    printf("Consumo estimado: %.2f kWh \n", consumo_energia);

    // Classifique o consumo como:
    // BAIXO, MODERADO ou ALTO.

    if(consumo_energia>40){
        printf("Classificação do consumo: ALTO \n");
    }else if(consumo_energia>=20){
        printf("Classificação do consumo: MODERADO \n");
    }else{
        printf("Classificação do consumo: BAIXO \n");
    }

    // Relatorio de custos
    // Exiba os custos calculados.

    printf("Custo da energia: R$ %.2f \n", custo_energia);
    printf("Custo da alimentação: R$ %.2f \n", custo_alimentacao);
    printf("Outros custos: R$ %.2f \n", outros_custos);
    printf("Custo total: R$ %.2f \n", custo_total);
    printf("Custo por participante: R$ %.2f \n\n", custo_por_participante);

    // Analise do orcamento

    printf("Orçamento disponível: R$ %.2f \n", orcamento);
    printf("Saldo: R$ %.2f \n", saldo);

    // Informe se o evento esta:
    // DENTRO DO ORCAMENTO,
    // NO LIMITE DO ORCAMENTO
    // ou ACIMA DO ORCAMENTO.

    printf("situação do orçamento: \n");

    // Decisao final
    // Informe se o evento esta:
    // APROVADO,
    // APROVADO COM RESSALVAS
    // ou NAO RECOMENDADO.

    return 0;
}
