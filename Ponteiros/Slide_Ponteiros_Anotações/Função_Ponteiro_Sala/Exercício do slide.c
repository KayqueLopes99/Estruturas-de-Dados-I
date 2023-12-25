//dia 06/12/2023
#include <stdio.h>// printf, scanf
#include <stdlib.h> // funções malloc, calloc, free, exit
#include <locale.h>
//Total de bites das estruturas pdf na pasta de linguagem c.
// Declaração de matriz m[0][0] primeira linha e coluna ,m[1][0]
/*Exercício: Aloque dinamicamente uma matriz de inteiros 5x5 e preencha cada
elemento da matriz com o seu respectivo índice (matriz[i][j] = i*5 + j). Em
seguida, imprima a matriz.
Nota: Não se esqueça de liberar a memória alocada a*/
int main(){
    //Já definido as linhas e colunas.
	int linhas = 5, colunas = 2, i, j;

	// Alocação das linhas.
	int **matriz = (int **) malloc(linhas * sizeof(int *));
	if (matriz == NULL) {
    printf("Falha na alocação de memória");
    return 1;
	}
	// Alocação das colunas e preenchimento da matriz.
	for (i =0; i < linhas; i++){
		matriz[i] = (int *) malloc(colunas * sizeof(int));
		for (j = 0; j < colunas; j++) {
            matriz[i][j] = i * colunas + j;//calculo da posição.
        }
	}
	 // Impressão da matriz na tela.
	 for (i = 0; i < linhas; i++) {
        printf("Matriz [%d]: ", i);
        for (j = 0; j < colunas; j++) {
            printf("%3d ", matriz[i][j]);//%3d server para deixar mais bonito :)
        }
        printf("\n");
    }
	
	//liberando
	for(i =0; i < linhas; i++){
		
		printf("Matriz [%d]:\n", i);
		free(matriz[i]);
	}
	free(matriz);
	
	return 0;
}
