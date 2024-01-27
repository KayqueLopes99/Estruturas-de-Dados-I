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

typedef struct {
	float preco;
	char local[50];
	char atracao[50];	
	
}Ingresso;


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


int main(void){
	int num_eventos;
	int j;
	   printf("Quantos eventos de anime você deseja cadastrar? ");
    scanf("%d", &num_eventos);
    Ingresso* i = (Ingresso*) malloc(num_eventos * sizeof(Ingresso));
  preenche(num_eventos, i);
    imprime(num_eventos, i);
    // loop para alterar o preço dos n eventos
       for (j = 0; j < num_eventos; j++) {
        altera_preco(i+j, (i+j)->preco);
    }
    imprime_menor_maior_preco(num_eventos, i);

    free(i);	
return 0;
	
}

