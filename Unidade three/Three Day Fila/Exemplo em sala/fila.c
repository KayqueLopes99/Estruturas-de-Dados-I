#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

 struct _fila
{
    int inicio, fim;
    int quantidade; // Num de elementos da Fila.
    int MAX_SIZE; // Tamanho Maxímo da fila.
    int *val; // Vetor de valores.
};

Fila *CriaFila(int MAX_SIZE){
Fila *Q = (Fila*) calloc(1, sizeof(Fila));

Q->val = (int*) calloc(MAX_SIZE, sizeof(int)); 
Q->MAX_SIZE = MAX_SIZE;
Q->quantidade = 0;
Q-> inicio = Q->fim = 0;

return Q;

}




void DestruirFila(Fila **Q){
    Fila *Variavel_auxiliar = *Q;
    free(Variavel_auxiliar->val);
    free(Variavel_auxiliar);
    *Q = NULL;

}

int Fila_vazia(Fila * Q){
    return (Q->quantidade == 0);
}

int Fila_cheia(Fila * Q){
    return (Q->quantidade == Q->MAX_SIZE);
}
int InsereFila(Fila *Q, int elemento){
    if(Fila_cheia(Q)){
        printf("Warning: Fila esta cheia\n");
        return 0; // Falha
    }else{
        Q->val[Q->fim] = elemento;
        Q->fim = (Q->fim+1) % Q->MAX_SIZE;
        Q->quantidade++;
        printf("Inserido: %d\n", elemento); // Imprime o elemento inserido
        return 1;
    }
}

int RemoveFila(Fila *Q){
    if (Fila_vazia(Q))
    {
        printf("Warning: Fila esta vazia\n");
        return 0; // Falha.
    }else{
        int elementoRemovido = Q->val[Q->inicio];
        Q->inicio = (Q->inicio+1) % Q->MAX_SIZE;
        Q->quantidade--;
        printf("Removido: %d\n", elementoRemovido); // Imprime o elemento removido
        return 1; // Sucesso.
    }
}



int ConsultaFila(Fila *Q, int *elemento){
if(Fila_vazia(Q)){
    printf("Warning: Fila esta vazia\n");
        return 0; // Falha.
}else{
       *elemento = Q->val[Q->inicio];
     
        return 1; // Sucesso.
    }
}