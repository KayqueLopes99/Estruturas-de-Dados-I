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
/*
void dados_pessoa(Pessoa * p){
int opcao;
printf("Informe o nome:\t");
scanf("%[^\n]", p->nome);
printf("\nInforme a idade:\t");
scanf("%d", &p->idade);
printf("Digite 1 para Cpf ou 0 para RG\n");
printf("Digite o seu cpf");
scanf("%d", &opcao);
if(opcao){
scanf("%[^\n]", p->doc.cpf);

}
else{
scanf("%[^\n]", p->doc.rg);
}
}
*/
    /* printf("Digite 1 para Cpf ou  2 para RG")
    if('1'){
        printf("Digite o seu cpf")
    }*/


int main(void){
   
    Pessoa * pessoa = malloc(sizeof(Pessoa));
    if (pessoa == NULL){
        exit(1);
    }
    dados_pessoa(pessoa); // passe o ponteiro 'pessoa', não o endereço do ponteiro
    printf("CPF = %s \n RG = %s", pessoa->doc.cpf, pessoa->doc.rg); // Exibição
    free(pessoa);
    return 0;
}
