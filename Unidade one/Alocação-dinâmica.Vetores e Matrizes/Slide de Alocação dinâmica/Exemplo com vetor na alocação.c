#include <stdio.h>
#include <stdlib.h>
int main() {
 int tamanho=5, i;
 int *vetor;
 // Alocando o vetor dinamicamente
 vetor = (int *) malloc(tamanho * sizeof(int));
 if (vetor == NULL) {
 printf("Erro ao alocar memória");
 exit(1);
 }
 // // Solicitando ao usuário que insira valores para preencher o vetor
 printf("Entre com os valores do vetor: \n");
 for (i = 0; i < tamanho; i++) {
 scanf("%d", &vetor[i]);
 }
 // Liberando a memória alocada
 free(vetor);
 return 0;
}