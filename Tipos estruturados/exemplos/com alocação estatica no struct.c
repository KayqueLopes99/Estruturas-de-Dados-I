#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura de aluno
struct aluno{
    char nome[20]; // 20bytes
    int idade; // 4 bytes
    int matricula; // 4 bytes
    char email[50]; // 50 bytes
};

// Fun��o para imprimir os dados do aluno
void imprime(struct aluno * estudante){
    printf("Nome: %s\n Idade: %d\n Matricula: %d\n Email: %s", estudante->nome, estudante->idade, estudante->matricula, estudante->email);
}

// Alocac�o estatica
int main(void){
    struct aluno estudante;
    printf("Digite o nome do aluno\n");
    scanf(" %[^\n]", estudante.nome);
    printf("Digite sua idade\n");
    scanf("%d", &estudante.idade);
    printf("Digite sua matricula\n");
    scanf("%d", &estudante.matricula);
    printf("Digite o Email\n");
    scanf(" %[^\n]", estudante.email);
    
    // Chamando a fun��o 'imprime' com o endere�o da estrutura 'estudante'
    imprime(&estudante);
    
    return 0;
}
/*
//ponteiro para a struct aluno
int main(void){
    struct aluno * estudante = (struct aluno*) malloc(sizeof(struct aluno));
    return 0;
}

//aloca��o dinamica
int main(void){
    struct aluno * estudante = (struct aluno*) malloc(sizeof(struct aluno));
    if (estudante == NULL){
        exit(1);
    }
    struct aluno estudante;
    printf("Digite o nome do aluno\n");
    scanf(" %[^\n]", estudante->nome);
    printf("Digite sua idade\n");
    scanf("%d", &estudante->idade);
    printf("Digite sua matricula\n");
    scanf("%d", &estudante->matricula);
    printf("Digite o Email\n");
    scanf(" %[^\n]", estudante->email);
    return 0;
}

//fun��o preenche
int main(void){
    struct aluno * estudante = (struct aluno*) malloc(sizeof(struct aluno));
    if (estudante == NULL){
        exit(1);
    }
    preenche(estudante);
    free (estudante);
    return 0;
}

//fun��o imprime
int main(void){
    struct aluno * estudante = (struct aluno*) malloc(sizeof(struct aluno));
    if (estudante == NULL){
        exit(1);
    }
    preenche(estudante);
    imprime(estudante);
    free (estudante);
    return 0;
}
  typedef para renomear a struct
typedef struct aluno{
    char nome[20];
    int idade;
    int matricula;
    char email[50];
} Aluno;


*/

