#include "disciplina.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct armazenador_de_dados_disciplina
{
    /* Dados da struct */
    char nome[100];
    int codigo;
};

Disciplina* cria_disciplina(char nome[], int codigo){
Disciplina *d = malloc(sizeof(Disciplina));// responsável por alucar cada um dos endereços dos dados. Tendo a mesma fução em aluno.c.
if(d == NULL){
 printf("Erro na alocacao.\n");
    exit(1);
}
// strncpy copia os dados associados ao nome que o usuario digita e vai colocando eles para d->nome para aloca-los em cada endereço. O mesmo na outra tad aluno.c.
  strncpy(d->nome, nome, sizeof(d->nome)-1);
    d->nome[sizeof(d->nome)-1] = '\0'; // para terminação NULL. 
    d->codigo = codigo;
    return d;

}
// solicitar informações sobre a disciplina.
Disciplina* Solicita_disciplina(){
    char nome[100];
    int codigo;
    printf("Digite o nome da disciplina: ");
    scanf("%s", nome);
    printf("Digite o codigo correspondente a disciplina: ");
    scanf("%d", &codigo);
    return cria_disciplina(nome, codigo);
}

// Liberação 
void exclui_disciplina(Disciplina* disciplina){
free(disciplina);

}