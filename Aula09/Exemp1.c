#include<stdio.h>
#include<locale.h>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    int idade=18, idade2=16;
    int *p =&idade;

    //p = &idade;

    printf("%d\n", idade);
    printf("%p\n", &idade); //mostra o código hexadecimal da memória ram em que 'idade' está sendo armazenado.
    printf("%p\n", p);
    printf("%d\n", *p); //busca o valor do ponteiro.

    /*printf("%d\n", idade2);
    printf("%p\n", &idade2);*/

    return 0;

}
