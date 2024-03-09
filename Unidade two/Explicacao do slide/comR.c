#include <stdio.h> 
#include <stdlib.h> 

int main(void)
{
    // Cria o arquivo: entrada.txt
    FILE * arquivo = fopen("entrada.txt", "r"); // Abre o arquivo "entrada.txt" para leitura
   
    char c[20]; // Declara um array de caracteres 'c' com tamanho 20 para armazenar strings
                
    if(arquivo == NULL) // Verifica.
    {
        printf("Erro na abertura do arquivo");
        exit(1); 
    }
    else
    {
        printf("feito\n"); // Imprime uma mensagem de sucesso se o arquivo foi aberto corretamente
    }

    fgets(c, 20, arquivo); // Lê uma string do arquivo e armazena na variável 'c'
    printf("%s\n", c); // Imprime a string lida

    if(!fclose(arquivo)) // Fecha o arquivo
    {
        printf("Fechado com sucesso !!!\n");
    }

    return 0;
}
