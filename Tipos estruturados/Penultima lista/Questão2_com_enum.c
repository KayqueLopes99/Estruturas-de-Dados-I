/*Escreva um programa que implementa uma struct Produto com os campos nome, preço e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto. */
// Com enum 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum alimentos{
	fruta = 1, bebida = 2,	eletronico = 3
} Alimentacao;


typedef struct
{
	char nome_alimento[20];
	float preco;
	Alimentacao produtos; 
} PRODUTO;

// Pede os dados e armazena e impreme.
void dados_produto(PRODUTO * p){
	int opcao;
	printf("Informe o nome do alimento:\n");
	scanf(" %[^\n]", p->nome_alimento);
	printf("Informe o preco do alimeneto:\n");
	scanf(" %f", &p->preco);

	printf("\n ========= Digite o tipo de alimento =======\n");
        	printf("======   1  -  fruta =======\n");
	        printf("======   2  -  bebida =======\n");
        	printf("======   3  -  eletronico =======\n");
scanf("%d", &opcao);
    switch(opcao){ 
        case 1:
            printf("FRUTA\n");
            // 'p' é um ponteiro para a struct PRODUTO, então 'p->produtos.tipo' acessa o campo 'tipo' da union 'produtos' na struct apontada por 'p'.
            p->produtos = fruta;
            break; 
        case 2:
            printf("BEBIDA\n");
            p->produtos = bebida;
            break; 
        case 3:
            printf("ELETRONICO\n");
            p->produtos = eletronico;
            break; 
        default:
            printf("Opção invalida\n");
            break; 
    }
}

int main(void){
	PRODUTO * Produto = (PRODUTO*)malloc(sizeof(PRODUTO));
    if (Produto == NULL){
        exit(1);
    }

    dados_produto(Produto);
printf("Alimento = %d \n Preco = %.2f \n", Produto->produtos, Produto->preco);


    free(Produto);
    return 0;
}
