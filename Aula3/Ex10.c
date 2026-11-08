#include<stdio.h>
#include<locale.h> //biblioteca de assentos.
#include<math.h> //biblioteca de funçoes matemáticas>

int main(){

    setlocale(LC_CTYPE, "Portuguese");

    float velInic, angulo;

    printf("Qual a velocidade inicial em (m/s)? ");
    scanf("%f", &velInic);

    printf("Qual ângulo inicial em graus? ");
    scanf("%f", &angulo);

    float radiano;

    radiano = angulo*(3.1415/180);

    printf("radiano: %.2f \n\n", radiano);

    float alcanceHori;

    alcanceHori = (pow(velInic, 2)*sin(2*radiano))/9,81 ; //alcance = (pow(v0, 2) * sin(2 * anguloRadianos)) / g;

    printf("O alcance horizontal estimado é %.2f", alcanceHori);

    return 0;
}
