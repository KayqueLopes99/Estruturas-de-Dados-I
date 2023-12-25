#include <stdio.h>

// Declaração da função recebe um ponteiro para int.
void incremento(int *ponteiro)
{
    // Incrementa o valor do ponteiro.
    (*ponteiro)++;
}

// Função principal.
int main()
{
    // Declaração e inicialização com o valor 5.
    int variavel = 5;

    // Chamada da função  passando o endereço.
    incremento(&variavel);

    // Impressão.
    printf("Valor da variavel: %d", variavel);

    // Retorno 0 com sucesso.
    return 0;
}
