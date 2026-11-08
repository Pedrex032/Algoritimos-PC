#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int i, calc;

    printf("Digite um numero int ");
    scanf("%d", &calc);

    printf("Tabuada do %d\n", calc);

    //FOR usado para quando se sabe exatamente a quantidade de vezes que o programa o precisará rodar
    for(i=0; i<=10; i++){
        printf("%d * %d = %d\n", calc, i, (calc*i));
    }

    return 0;

}
