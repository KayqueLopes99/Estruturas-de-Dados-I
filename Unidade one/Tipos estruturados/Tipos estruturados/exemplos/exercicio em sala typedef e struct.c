#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Disciplina com typedef
typedef struct disciplina{
    char nome[20]; 
    float nota; 
    int codigo; 
}Disciplina;

// Definição da estrutura Aluno com typedef
typedef struct aluno{
    char nome[20];
    int idade; 
    int matricula; 
    Disciplina * materias; 
}Aluno;

int main(void){
    Aluno *aluno = (Aluno*) malloc(sizeof(Aluno)); // Alocação de memória para a estrutura Aluno
    if(aluno == NULL){ // Verificacao
        exit(1);
    }

    // Alocação de memória para no máximo 2 disciplinas
    aluno -> materias = (Disciplina*) malloc(2*sizeof(Disciplina));
    if(aluno -> materias == NULL){ // Verificação se a alocação foi bem sucedida
        exit(1);
    }

    printf("informe os dados do aluno: \n");
    scanf(" %[^\n]", aluno -> nome); // Leitura do nome do aluno
    scanf("%d %d", &aluno->idade, &aluno->matricula); // Leitura da idade e matrícula do aluno

    int index;

    for(index = 0; index < 2; index++){ // Loop para cadastrar 2 disciplinas
        printf("Cadastro de disciplinas %d : \n", index+1);
        printf("Informe o nome: \n");
        scanf(" %[^\n]", aluno->materias[index].nome);
        printf("Informe a nota: \n");
        scanf("%f", &aluno->materias[index].nota);
        printf("Informe o codigo: \n");
        scanf("%d", &aluno->materias[index].codigo);
    }
    // Impressão das disciplinas cadastradas
    for(index = 0; index < 2; index++){
        printf("Disciplina %d : \n", index+1);
        printf("Nome: %s\nNota: %f\nCodigo: %d\n", aluno->materias[index].nome, aluno->materias[index].nota,
        aluno->materias[index].codigo);
    }

    return 0;
}
