/*
Questão 1) A estrutura de pilha pode ser implementada de várias maneiras, diferindo no que
diz respeito à natureza dos elementos, à forma como estes são armazenados e às operações
disponíveis para manipulação da pilha. Sendo assim, considere um tipo abstrato de dados para
representar uma pilha de valores reais, com as operações ilustradas em sala de aula.
Independentemente da estratégia de implementação, a interface do TAD pode ser dada pelo
arquivo pilha.h a seguir:
a) Implemente o TAD Pilha usando vetor dinâmico. Considere uma dimensão inicial para o
vetor no momento da criação da pilha; caso a capacidade da pilha seja atingida, você
pode realocar o vetor, duplicando sua capacidade em virtude de uma nova operação
de empilhamento.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilhinha.h"
#define N 20
int main() {
    Pilha* p = pilha_cria();
    int i;
    for(i = 1; i <= 20; i++){
    
        pilha_push(p, i);
    
}


    while(!pilha_vazia(p)) {
        printf("%.2f \t", pilha_pop(p));
    }

    pilha_libera(p);

    return 0;
}
