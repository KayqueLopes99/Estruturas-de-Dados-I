#include <stdio.h>
#include <string.h>
#include <locale.h>
//1. Implemente uma funcão que receba como parâmetro um vetor de números inteiros (vet) de tamanho
// n e inverta a ordem dos elementos armazenados nesse vetor.
//Sintaxe de função:
//tipo = void, nome = inversao, parâmetros = int v[] que é o vetor de tipo inteiro, n é o número de elemnetos 
void imprime_ordem(int v[], int n) {
    int i; // variável d loop for para percorer o vetor em cada espaço, imprimindo na tela com o printf 
    for (i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    for (i = n - 1; i >= 0; i--){// i = n -1 irá inverter o número, começando do 10 e parando até chegar a zero, com decremento i--.
		printf(" %d", v[i]);
	}
}

int main() {
    int vet[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};// declaração com o vetor com 10 elementos 
    setlocale(LC_ALL, "Portuguese");

    printf("Impressão dos números:\n");
    imprime_ordem(vet, 10); // chamei a função para imprimir o vetor e os números dele.
	printf("\nAgora vamos inverter a ordem dos números!\n"); 
	
    return 0;
}