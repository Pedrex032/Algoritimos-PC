#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#define PI 3.14159

int main()
{
    setlocale(LC_ALL, "Portuguese\n");

    int idade = 18;

    //printf("olá mundo");
    printf("Voçe tem %d anos de idade.\n", idade);

    system("pause");
    return 0;
}
