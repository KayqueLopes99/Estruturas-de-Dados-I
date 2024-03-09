#include <stdio.h>
#include <stdlib.h> 

int main(void)
{
    // Cria o arquivo: entrada.txt
    FILE* arquivo = fopen("entrada.txt", "wt"); // Abre o arquivo "entrada.txt" para escrita em modo texto
    int c;
                
    if(arquivo == NULL) // Verifica se o arquivo foi aberto corretamente
    {
        printf("Erro na abertura do arquivo"); // Imprime uma mensagem de erro se o arquivo não pôde ser aberto
        exit(1); // Sai do programa com um código de erro
    }
    else
    {
        printf("feito"); 
    }

    c = fgetc(arquivo); // Lê um caractere do arquivo e armazena na variável 'c'
    printf("%c\n", c);

    if(fclose(arquivo)) // Fecha.
    {
        printf("Fechado com sucesso !!!\n"); 
    }

    return 0; 
}
