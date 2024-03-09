#include <stdio.h>
#include <math.h>
#include "operacao.h"

int main(void){
    float numero1;
    float numero2;
    printf("Insira o numero 1\n");
    scanf("%f", &numero1);
    printf("Insira o numero 2 \n");
    scanf("%f", &numero2);
    printf("\n");

    operacao_sub(numero1, numero2);
    operacao_soma(numero1, numero2);
    operacao_mul(numero1, numero2);
    operacao_div(numero1, numero2);
    operacao_pot(numero1, numero2);

    return 0;
}