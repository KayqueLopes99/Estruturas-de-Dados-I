#include <stdio.h>
#include <stdlib.h>
#include "pilhinha.h"
#define N 20  // Define o tamanho máximo da pilha.

// Define a estrutura da pilha.
struct pilha
{
    int n;  // Quantidade de elementos na pilha.
    float* vetor_dinamico;  // Ponteiro para o vetor que armazena os elementos da pilha.
};


// Função para criar uma nova pilha.
Pilha * pilha_cria(void){
   Pilha * stack = (Pilha*) malloc(sizeof(Pilha));  // Aloca memória para a pilha.
   if(stack == NULL){  // Se a alocação falhar, encerra o programa.
       exit(1);
   }
   stack->vetor_dinamico = (float*) malloc(N*sizeof(float));  // Aloca memória para o vetor da pilha.
   if(stack->vetor_dinamico == NULL){  // Se a alocação falhar, encerra o programa.
       exit(1);
   }
   stack->n = 0;  // Inicializa o campo n com 0.
   return stack;  // Retorna o ponteiro para a pilha criada.
}


// Função para inserir um elemento na pilha.
void pilha_push(Pilha* p, float v) {
    if(p->n == N) {  // Se a pilha estiver cheia, encerra o programa.
        printf("Capacidade da pilha estourou.\n");
        exit(1);
    }
    // Insere o elemento na próxima posição livre do vetor.
    p->vetor_dinamico[p->n] = v;
    p->n++;  // Incrementa a quantidade de elementos na pilha.
}

// Função para verificar se a pilha está vazia.
int pilha_vazia(Pilha* p){
    return (p->n == 0);  // Retorna verdadeiro se a pilha estiver vazia e falso caso contrário.
}

// Função para liberar a memória alocada para a pilha.
void pilha_libera(Pilha * p){
    free(p);  // Libera a memória alocada para a pilha.
}

// Função para remover um elemento da pilha.
float pilha_pop(Pilha* p) {
    float v;
    if(pilha_vazia(p)) {  // Se a pilha estiver vazia, encerra o programa.
        printf("Pilha vazia.\n");
        exit(1);
    }
    // Retira o elemento do topo da pilha.
    v = p->vetor_dinamico[p->n-1];
    p->n--;  // Decrementa a quantidade de elementos na pilha.
    return v;  // Retorna o elemento removido.
}
