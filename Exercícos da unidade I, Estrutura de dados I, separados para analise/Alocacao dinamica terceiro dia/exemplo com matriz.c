//Exemplo: Multiplicação de Matrizes
#include <stdio.h>
#include <stdlib.h>
int main() {
 int linhasA, colunasA, linhasB, colunasB, i, j, k;
 printf("Entre com o número de linhas e colunas da matriz A: ");
 scanf("%d %d", &linhasA, &colunasA);
 printf("Entre com o número de linhas e colunas da matriz B: ");
 scanf("%d %d", &linhasB, &colunasB);
 // Verificando se as matrizes podem ser multiplicadas
 if (colunasA != linhasB) {
 printf("As matrizes não podem ser multiplicadas.\n");
 return 0;
 } // Alocando matriz A
 int **matrizA = (int **) malloc(linhasA * sizeof(int *));
 for (i = 0; i < linhasA; i++) {
 matrizA[i] = (int *) malloc(colunasA * sizeof(int));
 }
 // Alocando matriz B
 int **matrizB = (int **) malloc(linhasB * sizeof(int *));
 for (i = 0; i < linhasB; i++) {
 matrizB[i] = (int *) malloc(colunasB * sizeof(int));
 } // Lendo valores do usuário e armazenando nas matrizes
 printf("Entre com os valores da matriz A: \n");
 for (i = 0; i < linhasA; i++) {
 for (j = 0; j < colunasA; j++) {
 scanf("%d", &matrizA[i][j]);
 }
 }
 printf("Entre com os valores da matriz B: \n");
 for (i = 0; i < linhasB; i++) {
 for (j = 0; j < colunasB; j++) {
 scanf("%d", &matrizB[i][j]);
 }
 }
 // Alocando matriz C
 int **matrizC = (int **) malloc(linhasA * sizeof(int *));
 for (i = 0; i < linhasA; i++) {
 matrizC[i] = (int *) malloc(colunasB * sizeof(int));
 }
 for (i = 0; i < linhasA; i++) {
 for (j = 0; j < colunasB; j++) {
 for (k = 0; k < colunasA; k++) {
 matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
 }
 }
 }
 return 0;
}