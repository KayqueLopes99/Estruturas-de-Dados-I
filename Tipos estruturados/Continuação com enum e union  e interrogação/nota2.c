#include <stdio.h>
#include <stdlib.h>

typedef union documentos{
    char rg[15];
    char cpf[15];
} Documentos;

typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc; // armazenar o cpf ou rg.
} Pessoa;

void dados_pessoa(Pessoa * p){
    int opcao;
    printf("Informe o nome:\t");
    scanf(" %[^\n]", p->nome);
    printf("\nInforme a idade:\t");
    scanf("%d", &p->idade);
    printf("Digite 1 para Cpf ou 0 para RG\n");
    scanf("%d", &opcao);
    if(opcao){
        printf("Digite o seu cpf:\t");
        scanf(" %[^\n]", p->doc.cpf);
    }
    else{
        printf("Digite o seu rg:\t");
        scanf(" %[^\n]", p->doc.rg);
    }
}

int main(void){
   
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    if (pessoa == NULL){
        exit(1);
    }
    dados_pessoa(pessoa); // passe o ponteiro 'pessoa', não o endereço do ponteiro
    free(pessoa);
    return 0;
}
