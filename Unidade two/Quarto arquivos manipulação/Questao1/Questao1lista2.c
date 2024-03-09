
/*
Faça um programa em C que solicita ao usuário informaçõoes de funcionários via teclado. As informações digitadas pelo o usuário sao: id, nome e salário do funcionário. Armazene as informa¸coes
digitadas pelo usuario em um arquivo texto.

*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    FILE* one_arquivo = fopen("onequestionlisttwo.txt", "w");

    float id, salario;
    char nome[80];
    int i;
    int max_pessoa = 0;
    if(one_arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
        }
    else{
        printf("Arquivo aberto com sucesso\n");
    }

    printf("Digite o numero de pessoas\n");
    scanf("%d", &max_pessoa);

    for(i = 0; i < max_pessoa; i++){
        printf("Digite seu nome:\n");
        scanf("%s", nome);
        printf("Digite seu id:\n");
        scanf("%f", &id);
        printf("Digite seu salario:\n");
        scanf("%f", &salario);

        fprintf(one_arquivo, "Nome: %s\t ID: %.2f\n Salario: %.2f\n", nome, id, salario);
    }

    if(fclose(one_arquivo) == 0){
        printf("Arquivo fechado com sucesso !!!\n");
    }

    return 0;
}
