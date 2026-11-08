#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    char opcao;
    float diar, total;

    printf("Qual o tipo de hospedagem?\n");
    printf("[S] quarto simples\n");
    printf("[D] quarto duplo\n");
    printf("[T] quarto total\n");
    printf("Digite uma opção ");
    scanf(" %c", &opcao);

    printf("Qual a quantidade de diárias? ");
    scanf("%f", diar);

    //COM IF / ELSE:

    if(opcao=='s' || opcao=='S'){

        printf("O valor total e se pagar é: R$ %.2f", (diar*300));

    }else if(opcao=='d' || opcao=='D'){

        printf("O valor total e se pagar é: R$ %.2f", (diar*450));

    }else if(opcao=='t' || opcao=='T'){

        printf("O valor total e se pagar é: R$ %.2f", (diar*500));

    }else{
        printf("Opção invalida.");
    }

    //COM SWITCH CASE:

    /*switch (opcao){
        case's':
        case'S':
            total = (300.00*diar);
            break;
        case'd':
        case'D':
            total = (450.00*diar);
            break;
        case't':
        case'T':
            total = (500.00*diar);
            break;
        default:
            printf("Opção invalida.");
            return 0;
    }

    printf("O valor total e se pagar é: R$ %.2f", total);*/

    return 0;
}
