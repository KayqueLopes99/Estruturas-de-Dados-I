// TAD aluno.h
// Corrigir o IRA.
// aluno.c
#include "aluno.h" //Isso aqui representará a TAD
#include <stdlib.h>
#include <stdio.h>

struct aluno{
    char nome[20];
    int matricula;
    float IRA;
};

Aluno * recebe_dados(void){
    Aluno * estudante = (Aluno*) malloc(sizeof(Aluno));
    if(estudante == NULL){
        printf("Sem memória");
        exit(1);
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", estudante->nome);
    getchar();

    printf("Digite a matrícula do aluno: ");
    scanf("%d", &(estudante->matricula));
    getchar();

    printf("Digite o IRA do aluno: ");
    scanf("%f", &(estudante->IRA));
    getchar();

    return estudante;
}

void exibe_aluno(Aluno * exibe){
    printf("Nome do aluno: %s\n", exibe->nome);
    printf("Matrícula: %d\n", exibe->matricula);
    printf("IRA: %.1f\n", exibe->IRA);
}

void limpar(Aluno * aluno){
    free(aluno);
}