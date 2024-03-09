#include "disciplina.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    char nome[100];
    int matricula, codigo;
    Aluno* aluno;
    Disciplina* disciplina;
    char opcao1, opcao2;

    do{
        // Solicita os dados do aluno
        aluno = cria_Aluno(nome, matricula);
Solicita_dados(aluno);
        do{
            // Solicita os dados da disciplina
          
            disciplina = Solicita_disciplina();
            // Matricula o aluno na disciplina
            matricula_disciplina(aluno, disciplina);

            printf("Deseja adicionar outra disciplina? (s - sim / n - nao): ");
            scanf(" %c", &opcao1);
        } while(opcao1 == 's');

        printf("Deseja cadastrar outro aluno? (s - sim / n - nao): ");
        scanf(" %c", &opcao2);
    } while(opcao2 == 's');

    // Libera a memória alocada
    exclui_aluno(aluno);
    exclui_disciplina(disciplina);

    return 0;
}

/*
Questão 2) Você foi contratado por uma instituição educacional para desenvolver um sistema
de gerenciamento de alunos e disciplinas. Para isso, você precisa criar um conjunto de Tipos
Abstratos de Dados (TADs) que permitam a manipulação eficiente dos dados dos alunos e das
disciplinas oferecidas pela instituição.
*/