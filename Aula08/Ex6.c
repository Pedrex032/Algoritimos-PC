#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>
#define TEM 7

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    const char *diasSemana[]{"seg", "ter", "qua", "qui", "sex", "sab", "dom",}

    int i;

    for(i=0; i<TEM; i++){
        printf("Digite a temperatura da %s: ", diasSemana[i]);
    }

    return 0;

}
