#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// definindo a estrutura empresa.
struct empresa {
    char nome[20];        // 20 bytes
    float salario;        // 4 bytes
    int identificador;    // 4 bytes
    char cargo[30];        // 50 bytes
};

void preenche(struct empresa *funcionario) {
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
    printf("Funcionario: %s\n", funcionario->nome);
    printf("Salario: %.2f\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
    printf("\n");
}

void altera_salario(struct empresa *funcionario) {
    printf("Digite o novo salario para %s:\n", funcionario->nome);
    scanf("%f", &funcionario->salario);
    printf("Sua solicitacao de novo salario foi enviada.\n");
    printf("Novo Salario %.2f\n: ", funcionario->salario);
}

void mostra_menor_e_maior(struct empresa funcionarios[], int tamanho){
	int i;
 int maior = 0, menor = 0;
 for(i = 0; i < tamanho; i++){
 	printf("Lista : )\n");
 	 printf("Funcionrio %s:\n", funcionarios[i].nome);
        printf("Salario: %f\n", funcionarios[i].salario);
 }
  for (i = 1; i < tamanho; i++) {
        if (funcionarios[i].salario > funcionarios[maior].salario) {
            maior = i;
        }
        if (funcionarios[i].salario < funcionarios[menor].salario) {
            menor = i;
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

    printf("Digite o namero de funcionarios: ");
    scanf("%d", &numFuncionarios);

    struct empresa *funcionarios = (struct empresa *)malloc(numFuncionarios * sizeof(struct empresa));

    if (funcionarios == NULL) {
        printf("Erro na alocaaao de memaria!\n");
        exit(1);
    }

    // Preenchendo dados dos funcionarios
    for (int n = 0; n < numFuncionarios; n++) {
        printf("Funcionario %d:\n", n + 1);
        preenche(&funcionarios[n]);
    }

    // Exibindo informaações dos funcionarios
    for (int n = 0; n < numFuncionarios; n++) {
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
