/*Questão 1) Crie um tipo estruturado para armazenar dados de um ingresso. Uma estrutura deste tipo possui os
seguintes campos: preço, local e atração.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e
preencha seus campos com valores fornecidos pelo usuário via teclado. Protótipo: void
preenche(Ingresso* i);
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Ingresso e imprima
os valores dos seus campos. Protótipo: void imprime(Ingresso* i);
c) Escreva uma função que receba, como parâmetros, o endereço de uma estrutura do tipo Ingresso e um
novo valor de preço e atualize o preço do ingresso para o novo valor. Protótipo: void
altera_preco(Ingresso* i, float valor);
d) Escreva uma função que receba, como parâmetros, um vetor de ingressos e o tamanho do vetor e
imprima os eventos de ingresso mais barato e mais caro. Protótipo: void imprime_menor_maior_preco(int
n, Ingresso* vet);
e) Escreva uma função main para testar as funções anteriores.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ingresso.h"
// #include "ingresso.c" para vscode

int main(void){
	 int num_eventos;
     int j;
    printf("Quantos eventos de anime você deseja cadastrar? ");
    scanf("%d", &num_eventos);
    Ingresso* i = (Ingresso*) malloc(num_eventos * sizeof(Ingresso));

    for (j = 0; j < num_eventos; j++) {
        preenche(num_eventos, &i[j]);
         imprime(num_eventos, &i[j]);
        float novo_preco = 0.0;
        // Aqui você pode definir novo_preco como quiser
        altera_preco(&i[j], novo_preco);
    }

    imprime_menor_maior_preco(num_eventos, i);
	
    free(i);
    return 0;
}

