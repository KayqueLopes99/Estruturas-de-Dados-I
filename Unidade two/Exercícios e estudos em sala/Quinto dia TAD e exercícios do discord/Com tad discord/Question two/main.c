#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
FILE *question = fopen("folha.txt", "r");
if(question == NULL){
    printf("Erro na abertura");
    exit(1);
}
int numero_funcionarios_do_arquivo, i; 
fscanf(question, "%d", &numero_funcionarios_do_arquivo);


Funcionario* funcionarios[numero_funcionarios_do_arquivo];

    // Alocação de memória para cada funcionário
    for (i = 0; i < numero_funcionarios_do_arquivo; i++) {
        funcionarios[i] = (Funcionario*)malloc(sizeof(Funcionario));

    }
    // Preenchimento dos dados a partir do arquivo
    copia_dados(question, numero_funcionarios_do_arquivo, funcionarios);

    // impressão dos grupos A B C.
    imprime_folha(numero_funcionarios_do_arquivo, funcionarios, 'A');
    imprime_folha(numero_funcionarios_do_arquivo, funcionarios, 'B');
    imprime_folha(numero_funcionarios_do_arquivo, funcionarios, 'C');


    // Liberação da memória alocada
    for ( i = 0; i < numero_funcionarios_do_arquivo; i++) {
        free(funcionarios[i]);
    }
 if (fclose(question) == 0) {
        printf("Arquivo fechado com sucesso.\n");
    } else {
        printf("Erro ao fechar o arquivo.\n");
    }
return 0;
}