#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*1. Crie um tipo estruturado para armazenar dados de um funcionário. 
Uma estrutura deste tipo possui os seguintes campos: nome, salário, identificador e cargo.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario
e preencha seus campos com valores fornecidos pelo usuário via teclado.
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Funcionario 
e imprima os valores dos seus campos. 
c) Implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario. 
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Funcionario e imprima
o cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário com o menor salário.*/
// definindo a estrutura empresa.
struct empresa { //Declaracao das variaveis.
    char nome[20];        // 20 bytes.
    float salario;        // 4 bytes.
    int identificador;    // 4 bytes.
    char cargo[30];        // 30 bytes.
};

void preenche(struct empresa *funcionario) { 
	// preencher dados.
    printf("Digite o nome do querido funcionario:\n");
    scanf(" %[^\n]", funcionario->nome);
    printf("Digite o salario:\n");
    scanf("%f", &funcionario->salario);
    printf("Digite o identificador:\n");
    scanf("%d", &funcionario->identificador);
    printf("Digite o cargo:\n");
    scanf(" %[^\n]", funcionario->cargo);
}

void imprime(struct empresa *funcionario) {
	// imprimir
    printf("Funcionario: %s\n", funcionario->nome);
    printf("Salario: %.2f\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("\n");
}

void altera_salario(struct empresa *funcionario) {
	// alterar salario
    printf("Digite o novo salario para %s:\n", funcionario->nome);
    scanf("%f", &funcionario->salario);
    printf("Sua solicitacao de novo salario foi enviada.\n");
    printf("Novo Salario %.2f\n: ", funcionario->salario);
}

void mostra_menor_e_maior(struct empresa funcionarios[], int tamanho){
	int i; // Declaração da variavel do loop
    int maior = 0, menor = 0; // Declaracao das variaveis que vai  armazenar os índices do funcionario com maior e menor salário

    // Loop para imprimir a lista
    for(i = 0; i < tamanho; i++){
        printf("Lista : )\n"); 
        printf("Funcionario %s:\n", funcionarios[i].nome); 
        printf("Salario: %f\n", funcionarios[i].salario); 
    }

    // Loop para encontrar o funcionário com maior e menor salário
    for (i = 1; i < tamanho; i++) {
        if (funcionarios[i].salario > funcionarios[maior].salario) { // Se o salario atual for maior que o salario do funcionario com maior salario
            maior = i; // Atualiza
        }
        if (funcionarios[i].salario < funcionarios[menor].salario) { // Se o salario atual for menor que o salario do funcionario com menor salario
            menor = i; // Atualiza
        }
    }

    printf("funcionario %s com maior salario :\n", funcionarios[maior].nome);
    printf("Salario: %.2f\n", funcionarios[maior].salario);
    printf("Cargo: %s\n", funcionarios[maior].cargo);

    printf("funcionario %s com menor salario :\n", funcionarios[menor].nome);
    printf("Salario: %.2f\n ", funcionarios[menor].salario);
    printf("Cargo: %s\n", funcionarios[menor].cargo);
}



int main(void) {
    setlocale(LC_ALL, "portuguese");
    int numFuncionarios;
    int n;
    printf("Digite o namero de funcionarios: ");
    scanf("%d", &numFuncionarios);

    struct empresa *funcionarios = (struct empresa *)malloc(numFuncionarios * sizeof(struct empresa));

    if (funcionarios == NULL) {
        printf("Erro na alocaaao de memaria!\n");
        exit(1);
    }

    // Preenchendo dados dos funcionarios

    for (n = 0; n < numFuncionarios; n++) {
        printf("Funcionario %d:\n", n + 1);
        preenche(&funcionarios[n]);
    }

    // Exibindo informaações dos funcionarios
    for ( n = 0; n < numFuncionarios; n++) {
        printf("Detalhes do Funcionario %d:\n", n + 1);
        imprime(&funcionarios[n]);

        // Perguntando se deseja alterar o salario
        char resposta;
        printf("Deseja alterar o salario para este funcionario? (S/N): ");
        scanf(" %c", &resposta);
        
        if (resposta == 'S' || resposta == 's') {
            altera_salario(&funcionarios[n]);
        }
    }
mostra_menor_e_maior(funcionarios, numFuncionarios);


    // Liberando a memaria alocada para o array de funcionarios.
    free(funcionarios);
    return 0;
}
