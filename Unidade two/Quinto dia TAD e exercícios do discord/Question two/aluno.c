#include "disciplina.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Um struct com os dados.
struct aluno
{
    char nome[100];
    int matricula;
    Disciplina* disciplinas[10];
    int num_diciplinas;
};




Aluno* cria_Aluno(char nome[], int matricula){
Aluno *A = malloc(sizeof(Aluno));
if(A == NULL){
 printf("Erro na alocacao.\n");
    exit(1);
}
   strncpy(A->nome, nome, sizeof(A->nome)-1);
    A->nome[sizeof(A->nome)-1] = '\0'; // para terminação NULL. 
    A->matricula = matricula;
    A->num_diciplinas = 0;
 return A;
}

void matricula_disciplina(Aluno* aluno, Disciplina*
disciplina){
// Verificar se o aluno pode se matricular em mais diciplinas no caso temos até 10.
if(aluno->num_diciplinas < 10){
        aluno->disciplinas[aluno->num_diciplinas] = disciplina;
        aluno->num_diciplinas++;
        printf("Cadastro feito.\n");
    } else {
        printf("Aluno atingiu numero max de disciplinas.\n");
    }
}

// Solicitação e dados.
void Solicita_dados(Aluno* aluno){
    printf("Digite o seu nome: ");
    scanf("%s", aluno->nome);

    printf("Digite a sua matricula: ");
    scanf("%d", &(aluno->matricula));
}

// Função de liberação.
void exclui_aluno(Aluno* aluno){
    free(aluno);
}