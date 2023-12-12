#include <stdio.h>

// Declaração da função incremento.
void incremento(int *ponteiro)
{
    // Incrementa o valor.
    (*ponteiro)++;
}


// Função principal.
int main()
{
    // Declaração e inicialização da variável com o valor 5.
    int variavel = 5;

    // Chamada da função passando o endereço com o incremento.
    incremento(&variavel);

    // Impressão.
    printf("Valor da variavel: %d", variavel);

    // Retorno 0 indicando sucesso.
    return 0;
}

