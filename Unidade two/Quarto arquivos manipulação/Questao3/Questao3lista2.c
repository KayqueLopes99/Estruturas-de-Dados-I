/*
3. Vocˆe foi contratado para desenvolver um programa em C que permita o cadastro de frutas e seus
pre¸cos em um arquivo de dados. O programa deve usar uma estrutura (struct) para armazenar os
detalhes de cada fruta, incluindo o nome da fruta e o pre¸co.
O programa deve realizar as seguintes a¸c˜oes:
Definir uma estrutura chamada Fruta com os seguintes campos:
– nome (string) para armazenar o nome da fruta.
– preco (float) para armazenar o pre¸co da fruta.
Permitir que o usu´ario insira os dados das frutas via teclado.
O usu´ario poder´a cadastrar m´ultiplas frutas em uma ´unica execu¸c˜ao do programa. Para cada fruta,
o programa deve solicitar:
O nome da fruta.
O pre¸co da fruta.
Ap´os inserir os dados de cada fruta, o programa deve salvar as informa¸c˜oes no arquivo ”frutas.txt”.
Cada linha do arquivo deve conter o nome da fruta e seu pre¸co, separados por v´ırgula.
O programa deve continuar solicitando os dados das frutas at´e que o usu´ario decida parar.
Quando o usu´ario decidir parar de cadastrar frutas, o programa deve exibir uma mensagem de encerramento e fechar o arquivo.
*/


#include <stdio.h>
#include <stdlib.h>

struct armazeador_frutas
{
 float fruta;
 char nome_fruta[80];
};

int main(void){
   FILE* terceiro_arquivo = fopen("threequestionlisttwo.txt", "w");

   if(terceiro_arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    else{
        printf("Arquivo aberto com sucesso\n");
    }
   struct armazeador_frutas fruta;
    char continuar;

    do{
        printf("\n---------- Cadastro da fruta -----------\n");

        printf("Informe o nome da fruta: ");
        scanf("%s", fruta.nome_fruta);

        printf("Informe p preco da fruta: ");
        scanf("%f", &fruta.fruta);

        fprintf(terceiro_arquivo, "\n--------- As frutinhas --------------\n");
        fprintf(terceiro_arquivo, "Nome da fruta: %s\n", fruta.nome_fruta);
        fprintf(terceiro_arquivo, "preco da fruta: %.2f\n", fruta.fruta);

        printf("\nDeseja cadastrar outra fruta? (S/N): ");
        scanf(" %c", &continuar);
        getchar(); // Limpa o teclado

    } while(continuar == 'S' || continuar == 's');

    if(fclose(terceiro_arquivo) == 0){
        printf("Arquivo fechado com sucesso !!!\n");
    }
  
    return 0;
}
