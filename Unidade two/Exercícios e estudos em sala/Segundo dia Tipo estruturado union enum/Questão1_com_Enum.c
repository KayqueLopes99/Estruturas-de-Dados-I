/*
Escreva um programa que implementa uma struct Pessoa com os campos nome, idade e gˆenero. O
gˆenero deve ser armazenado como um enum com os valores MASCULINO e FEMININO. O programa
deve ler os dados de uma pessoa e imprimir os dados da pessoa.
Com Enum.
*/
#include <stdio.h>
#include <stdlib.h>

// Um enum para para gênero.
typedef enum {
    Masculino = 'M',
    Feminino = 'F' 
} Genero;

// Estrutura para representar a pessoa.
typedef struct pessoa{
    char nome[20];
    int idade;
    Genero armazenamento_de_genero; // Usando o enum Genero.
}PESSOA;

// Função para ler e imprimir.
void impressao_preenche (PESSOA* p){ 
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
            p->armazenamento_de_genero = Masculino; // Armazenando o gênero na estrutura do enum.
            break; 
        case 2:
            printf("Feminino\n");
            p->armazenamento_de_genero = Feminino; // Armazenando o gênero na estrutura do enum.
            break; 
        default:
            printf("Opção invalida\n");
            break; 
    }
    printf("====== Dados =======\n");
    printf("Nome: %s\n", p->nome);// p acessa a varíavel.
    printf("Idade: %d\n", p->idade);
    printf("Genero: %c\n", p->armazenamento_de_genero); 
}

int main(void){
    PESSOA * pessoa = (PESSOA*) malloc(sizeof(PESSOA)); // Alocando memória para a estrutura PESSOA.
    if (pessoa == NULL){
        exit(1);
    }
    impressao_preenche (pessoa); // Chamando a função.
    free(pessoa); // Liberando a memória alocada.
    return 0;
}