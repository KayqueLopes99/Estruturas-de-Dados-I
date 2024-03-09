/*
Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gˆenero. O
gˆenero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa.
COM UNION.
*/
#include <stdio.h>
#include <stdlib.h>

typedef union {
    char genero;
} Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos armazenamento_de_genero;
}PESSOA;

void impressao (PESSOA* p){ 
    int opcao;    
    printf("Informe o nome:\n");
    scanf("%[^\n]", p->nome);
    printf("Informe a idade:\n");
    scanf("%d", &p->idade);
    printf("Para colacar seu gênero digite:\n");
    printf("========== 1 - masculino ======\n");
    printf("========== 2 - Feminino  ======\n");
    scanf("%d", &opcao); 
    switch(opcao){ 
        case 1:
            printf("Masculino\n");
            p->armazenamento_de_genero.genero = 'M'; // Corrigido para 'M'
            break; 
        case 2:
            printf("Feminino\n");
            p->armazenamento_de_genero.genero = 'F'; // Corrigido para 'F'
            break; 
        default:
            printf("Opção invalida\n");
            break; 
    }
    printf("====== Dados =======\n");
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Genero: %c\n", p->armazenamento_de_genero.genero); // Corrigido para imprimir 'M' ou 'F'
}

int main(void){
	PESSOA * pessoa = (PESSOA*) malloc(sizeof(PESSOA));
    if (pessoa == NULL){
        exit(1);
    }
    impressao (pessoa);
    return 0;
}