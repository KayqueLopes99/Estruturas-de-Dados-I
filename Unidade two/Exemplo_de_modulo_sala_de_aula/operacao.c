#include <stdio.h>
#include <math.h>
#include "operacao.h"

void operacao_sub(float numero1, float numero2){
    float resultado;
    printf("Subtracao:\n");
    resultado = numero2 - numero1;
    printf("Resultado da subtracao %.2f\n", resultado);
}

void operacao_soma(float numero1, float numero2){
    float resultado;
    printf("Soma:\n");
    resultado = numero2 + numero1;
    printf("Resultado da soma %.2f\n", resultado);
}

void operacao_mul(float numero1, float numero2){
    float resultado;
    printf("Multiplicacao:\n");
    resultado = numero2 * numero1;
    printf("Resultado da multiplicacao %.2f\n", resultado);
}

void operacao_div(float numero1, float numero2){
    if(numero2 != 0){
        float resultado;
        printf("Divisao:\n");
        resultado = numero1 / numero2;
        printf("Resultado da divisao %.2f\n", resultado);
    } else {
        printf("Erro: Divisao por zero nao e permitida.\n");
    }
}

void operacao_pot(float numero1, float numero2){
    float resultado;
    printf("Potenciacao:\n");
    resultado = pow(numero1, numero2);
    printf("Resultado da potenciacao %.2f\n", resultado);
}
