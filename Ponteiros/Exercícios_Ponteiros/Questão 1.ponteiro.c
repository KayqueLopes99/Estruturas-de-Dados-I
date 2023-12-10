#include <stdio.h>

/* Questão 1) Quais serão os valores de x, y e p ao final do trecho 
de código abaixo: */
int main() {
    int x, y, *p;
    y = 0;
    p = &y;
    x = *p; 
    x = 4;   
    (*p)++;  
    --x;     
    (*p) += x;  
}

// Y será 4, pois inicialmente é zero e está associado com o 
// conteúdo do ponteiro p no seu endereço. Na operação (*p) += x, 
// como y = p, resultará em 4.
// *P inicialmente é igual ao endereço de y = 0, logo com o incremento
// e depois (*p) += x, resultará em p = 4.
// X será 3, pois sofreu um decremento de uma unidade em --x;
