#include <stdio.h>
#include <stdlib.h>
#include "ingresso.h"



void preenche(int num_eventos, Ingresso* i){
	int j;
	// loop para preencher n eventos
    for (j = 0; j < num_eventos; j++) {
    	printf("Evento Crunchyroll %d\n", j+1);
        printf("Informe o preco do ingresso do evento Otaku: \n");
        scanf("%f",&(i+j)->preco);
        printf("Informe o local do evento Otaku: \n");
        scanf(" %[^\n]", (i+j)->local);
        printf("Informe a atracao do evento Otaku: \n");
        scanf(" %[^\n]", (i+j)->atracao);
    }
}

void imprime(int num_eventos, Ingresso* i){
	int j ;
		// loop para listar n eventos
	for (j = 0; j < num_eventos; j++) {
printf("========= Dados do Evento Crunchyroll %d ========\n", j+1);
	printf("O preço do evento Otaku: %.2f\n", (i+j)->preco);
	printf("O local do evento Otaku: %s\n", (i+j)->local);
	printf("A atracao do evento Otaku: %s\n", (i+j)->atracao);
}
}


void altera_preco(Ingresso* ingre, float valor){
    char resposta;
    printf("Deseja atualizar o preco do seu ingresso? s = sim n = nao\n");
    scanf(" %c", &resposta);
    if(resposta == 's'){
        printf("Digite o novo valor do ingresso: \n");
        scanf("%f", &valor);
        ingre->preco = valor;
        printf("Valor atualizado %.2f \n", valor);
    }
    else{
        printf("Nao!\n");
    }
}

void imprime_menor_maior_preco(int num_eventos, Ingresso* i){
	// O primeiro é o maior e o menor inicialmente até vim o próximo.
    float maior_preco = i->preco;
    float menor_preco = i->preco;
    int maior = 0, menor = 0;// inicialização com zero.
int j;
// loop para percorer os eventos
    for (j = 1; j < num_eventos; j++) {
        if ((i+j)->preco > maior_preco) {
            maior_preco = (i+j)->preco;
            maior = j;
        }
        if ((i+j)->preco < menor_preco) {
            menor_preco = (i+j)->preco;
            menor = j;
        }
    }
    printf("O evento Crunchyroll caro é %s, com preco de %.2f\n", (i+maior)->atracao, maior_preco);
    printf("O evento Crunchyroll  barato é %s, com preco de %.2f\n", (i+menor)->atracao, menor_preco);
}