#include <stdio.h>// printf, scanf
#include <stdlib.h> // funções malloc, calloc, free, exit
#include <locale.h>

int main(void){
	setlocale(LC_ALL, "portuguese");
	int tamanho = 5;
	int contador;
	int * vetor = (int*)malloc(tamanho*sizeof(int));
	if (vetor == NULL){
		exit(1);
	}
	else {
		printf("Alocação realizada com sucesso\n");
	}
	//Ler os dados do vetor:
	printf("Digite os valores do vetor\n");
 for (contador=0; contador<tamanho; contador++){
	 scanf("%d", &vetor[contador]);
 }	 
 free(vetor);
 
 return 0;
}