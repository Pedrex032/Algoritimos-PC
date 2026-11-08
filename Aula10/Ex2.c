#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

void trocar(int *a, int *b){

    int auxiliar;
    auxiliar = *a;

    *a = *b;
    *b = auxiliar;
}

int main() //int main é uma função e return é seu resultado geralmente retorna 0
{

    setlocale(LC_CTYPE, "Portuguese");

    int a, b;

    printf("digite o valor de a ");
    scanf("%d", &a);
    printf("digite o valor de b ");
    scanf("%d", &b);

    printf("Antes: a= %d b= %d\n", a, b);

    trocar(&a, &b);

    printf("Agora: a= %d b= %d", a, b);

    return 0;
}
