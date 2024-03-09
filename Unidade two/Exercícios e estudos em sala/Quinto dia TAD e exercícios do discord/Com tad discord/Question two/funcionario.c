#include "funcionario.h"
#include <stdio.h>
#include <stdlib.h>

// Função para pegar os dados do .txt e ler.
void copia_dados(FILE *fl, int n, Funcionario** pessoal){
    int i;
    // loop para ler a quantidade n de cada funcionário e seus dados.
    for(i = 0; i < n; i++){
        fscanf(fl, "%d %s %c %f", &pessoal[i]->funcional, pessoal[i]->nome, &pessoal[i]->departamento, &pessoal[i]->salario);
    }
}


// Função imprime dados e o resultado.
void imprime_folha(int n, Funcionario** pessoal, char depto){
    float total_salario = 0.0;
    int i;
    printf("Folhinha de pagamento : ) %c\n", depto);
    printf("Funcional\tNome\t\tDepto\tSalario\n");
    // lopp para percorrer a quantidade de funcioanarios.txt e imprimi-los em cada grupo abc separadamente.
    for (i = 0; i < n; i++) {
        // Se é do departamento.
        if (pessoal[i]->departamento == depto) {
            // imprime as informações.
            printf("%d\t\t%s\t\t%c\t%.2f\n", pessoal[i]->funcional, pessoal[i]->nome, pessoal[i]->departamento, pessoal[i]->salario);
            // Vai somando em cada grupo a b c.
            total_salario += pessoal[i]->salario;
        }
    }
    
    printf("Valor do grupo correspondente: R$ %.2f\n\n", total_salario);
}
