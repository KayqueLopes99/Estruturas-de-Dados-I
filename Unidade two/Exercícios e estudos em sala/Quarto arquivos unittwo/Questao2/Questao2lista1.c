// Implemente um programa em C para ler o nome e as notas de um núumero N de alunos e armazená-los
// em um arquivo.

#include <stdio.h>
#include <stdlib.h>
int main(void){
    FILE* segundo_arquivo = fopen("twoquestionlisttwo.txt", "w");
    char nome[80];
float numero;
int max_alunos = 0;
int i;
    if(segundo_arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
        }
    else{
        printf("Arquivo aberto com sucesso\n");
    }

printf("Digite o numero de alunos\n");
scanf("%d", &max_alunos);

for(i = 0; i < max_alunos; i++){

printf("Digite o nome do aluno\n");
scanf("%s", &nome);
printf("Digite o numero do aluno\n");
scanf("%f", &numero);
 fprintf(segundo_arquivo, "%s %.2f\n", nome, numero);
}


 if(fclose(segundo_arquivo) == 0){
        printf("Arquivo fechado com sucesso !!!\n");
    }
    return 0;
}