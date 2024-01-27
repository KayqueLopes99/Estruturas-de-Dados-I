/*Escreva um programa que implementa uma struct Produto com os campos nome, preço e tipo. O
tipo deve ser armazenado como uma union que armazena um dos tipos: ALIMENTO, BEBIDA ou
ELETRONICO. O programa deve ler os dados de um produto e imprimir os dados do produto. 
COM UNIO*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Está union contém o tipo para saber. 
typedef union alimentos{
	char tipo[15];
} Alimentacao;

typedef struct
{
	char nome_alimento[20];
	float preco;
	Alimentacao produtos; 
} PRODUTO;

// Pede os dados e armazena e impreme.
// Dependendo da escolha do usuário, ela armazena o tipo correspondente na variável 'tipo' da union 'produtos'.
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
            strcpy(p->produtos.tipo, "Fruta");
            break; 
        case 2:
            printf("BEBIDA\n");
            strcpy(p->produtos.tipo, "Bebida");
            break; 
        case 3:
            printf("ELETRONICO\n");
            strcpy(p->produtos.tipo, "Eletronico");
            break; 
        default:
            printf("Opção invalida\n");
            break; 
    }
}

// Função main(): Esta função aloca memória para a struct PRODUTO, coleta os detalhes do produto usando a função dados_produto() e, em seguida, libera a memória alocada.
// Ela também verifica se a alocação de memória foi bem-sucedida. Se não foi, ela termina o programa.
int main(void){
	PRODUTO * Produto = (PRODUTO*)malloc(sizeof(PRODUTO));
    if (Produto == NULL){
        exit(1);
    }

    dados_produto(Produto);
    printf("Alimento = %s \n Preco = %.2f \n", Produto->produtos.tipo, Produto->preco);

    free(Produto);
    return 0;
}
