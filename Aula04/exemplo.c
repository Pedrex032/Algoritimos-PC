#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int num;

    printf("Digite um número ");
    scanf("%d", &num);

    if(num%2==0){
        printf("O número %d é par\n", num);
    }else{
        printf("O número %d é impar\n", num);
    }

    return 0;
}
