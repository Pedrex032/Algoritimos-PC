#include<stdio.h>
#include<math.h>
#include<locale.h>

int main(void)
{
    setlocale(setlocale,"");
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
    printf("============= ARENA TECH =============\n");
    printf("qunatidade total de jogadores: ");
    scanf("%d",&qte_participantes);

    printf("Quantidade de jogadores em cada time: ");
    scanf("%d",&qte_jogadores_por_time);

    printf("Quantidade de computadores disponíveis: ");
    scanf("%d",&qte_computadores);

    printf("Potência média de cada computador, em watts: ");
    scanf("%f",&potencia);

    printf("Duração do evento, em horas: ");
    scanf("%f",&duracao);

    printf("Preço de 1 kWh de energia ");
    scanf("%f",&preco_kwh);

    printf("Preço de um kit de alimentação por participante: ");
    scanf("%f",&preco_kit);

    printf("Outros custos do evento: ");
    scanf("%f",&outros_custos);

    printf("Orçamento máximo disponível para o evento : ");
    scanf("%f",&orcamento);


    // Calculos
    qte_times = ceil(qte_participantes/qte_jogadores_por_time);
    consumo_energia = (qte_computadores*potencia*duracao)/1000;
    custo_energia = consumo_energia*preco_kwh;
    custo_alimentacao = qte_participantes*preco_kit;
    custo_total = custo_energia + custo_alimentacao + outros_custos;
    custo_por_participante = custo_total / qte_participantes;
    saldo = orcamento - custo_total;

    // Relatorio geral
   printf("\n===== ARENA TECH ==============\n");
    printf("Participantes: %d\n", qte_participantes);
    printf("Times necessarios: %d\n",qte_times);
    printf("Computadores disponiveis: %d\n", qte_computadores);

    // Decisão de Infraestrutura
    if (qte_computadores >= qte_participantes) {
        printf("Infraestrutura: SUFICIENTE\n\n");
    } else {
        printf("Infraestrutura: INSUFICIENTE (Faltam %d computadores)\n\n", qte_participantes - qte_computadores);
    }

    // Decisão do Consumo
    printf("Consumo estimado: %.2f kWh\n", consumo_energia);
    printf("Classificacao do consumo: ");
    if (consumo_energia <= 20) {
        printf("BAIXO\n");
    } else if (consumo_energia <= 40) {
        printf("MODERADO\n");
    } else {
        printf("ALTO\n");
    }

    // Exibição dos Custos
    printf("Custo da energia: R$ %.2f\n", custo_energia);
    printf("Custo da alimentacao: R$ %.2f\n", custo_alimentacao);
    printf("Outros custos: R$ %.2f\n", outros_custos);
    printf("CUSTO TOTAL: R$ %.2f\n", custo_total);
    printf("CUSTO POR PARTICIPANTE: R$ %.2f\n", custo_por_participante);
    printf("Orcamento disponivel: R$ %.2f\n", orcamento);
    printf("Saldo: R$ %.2f\n\n", saldo);

    // Decisão do Orçamento (Margem de segurança de 5%)
    printf("Situacao do orcamento: ");
    if (custo_total > orcamento) {
        printf("ACIMA DO ORCAMENTO\n");
    } else if (saldo <= (orcamento * 0.05)) {
        printf("NO LIMITE DO ORCAMENTO\n");
    } else {
        printf("DENTRO DO ORCAMENTO\n");
    }

      if (qte_computadores < qte_participantes || custo_total > orcamento) {
        printf("DECISAO FINAL: NAO RECOMENDADO\n");
        printf("Motivo: ");
        if (qte_computadores < qte_participantes && custo_total > orcamento) {
            printf("infraestrutura insuficiente e custo acima do orcamento.\n");
        } else if (qte_computadores < qte_participantes) {
            printf("infraestrutura insuficiente de computadores.\n");
        } else {
            printf("custo total acima do orcamento disponivel.\n");
        }
    } else if (consumo_energia > 40.0f) {
        printf("DECISAO FINAL: APROVADO COM RESSALVAS\n");
        printf("Motivo: consumo elevado de energia.\n");
    } else {
        printf("DECISAO FINAL: APROVADO\n");
        printf("Motivo: infraestrutura e orcamento adequados.\n");
    }






    return 0;
}
