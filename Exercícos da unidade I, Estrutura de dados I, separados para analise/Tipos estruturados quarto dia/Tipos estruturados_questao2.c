/*
2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os seguintes campos: nome da pessoa, n�mero do documento e idade.
a) Escreva uma fun��o que receba como par�metro o endere�o de uma estrutura do tipo Pessoa e preencha seus campos com valores fornecidos pelo usu�rio via teclado.
b) Escreva uma fun��o que receba como par�metro o endere�o de uma estrutura do tipo Pessoa e imprima os valores dos seus campos.
c) Implemente uma fun��o para realizar uma atualiza��o da idade de uma estrutura do tipo Pessoa.
d) Escreva uma fun��o que receba como par�metro um vetor de estruturas do tipo Pessoa e imprima o nome da Pessoa mais velha e mais nova.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Definindo a estrutura dadinhos.
struct dadinhos
{
	char nome[20];        
	int  numero_documento;
	int idade;            
};

// Fun��o para preencher os dados do usu�rio
void escreve(struct dadinhos *pessoal)
{
	printf("Digite o nome do usu�rio:\n");
	scanf("%s", pessoal->nome); 
	printf("Digite o n�mero do documento:\n");
	scanf("%d", &pessoal->numero_documento); 
	printf("Digite a sua idade:\n");
	scanf("%d", &pessoal->idade); 
}

// Fun��o para imprimir os dados do usu�rio
void imprime(struct dadinhos *pessoal)
{
	printf("O nome do senhor(a): %s\n", pessoal->nome); // Imprimindo o nome 
	printf("N�mero correspondente ao seu documento: %d\n", pessoal -> numero_documento); // Imprimindo o n�mero do documento
	printf("Sua idade no sistema: %d\n", pessoal->idade); // Imprimindo a idade
	printf("\n");
}
// Fun��o para alterar a idade
void alterar_idd(struct dadinhos *pessoal){
	printf("Atualiza��o de idade do senhor(a): \n");
	printf("Digite a nova idade para atualiza��o %s:\n", pessoal->nome); 
	scanf("%d", &pessoal->idade);
	printf("Idade atualizada com extremo sucesso !!!!!!!!!!\n Idade atual:  %d\n:", pessoal->idade); // Imprimindo a nova idade 
}

// Fun��o para encontrar o usu�rio mais velho e mais novo
void saber_quem_e(struct dadinhos pessoals[], int tamanho) {
	int i;
	int velho = 0, novo = 0; // Inicializando as vari�veis velho e novo
	for (i = 1; i < tamanho; i++) {
		if (pessoals[i].idade > pessoals[velho].idade) { // Se a idade do usu�rio atual � maior que a idade do usu�rio mais velho
			velho = i; 
		}
		if (pessoals[i].idade < pessoals[novo].idade) { // Se a idade do usu�rio atual � menor que a idade do usu�rio mais novo
			novo = i; 
		}
	}
	printf("usu�rio %s com muita idade :\n", pessoals[velho].nome); // Imprimindo o nome do usu�rio mais velho
	printf("idade: %d\n", pessoals[velho].idade); // Imprimindo a idade do usu�rio mais velho
	printf("usu�rio %s mais novo :\n", pessoals[novo].nome); // Imprimindo o nome do usu�rio mais novo
	printf("idade: %d\n ", pessoals[novo].idade); // Imprimindo a idade do usu�rio mais novo
}

int main()
{
	setlocale(LC_ALL, "portuguese"); 
	int num_de_pessoas;
int n;
	printf("Quantas cidad�os o senhor(a) deseja cadastrar: ");
	scanf("%d", &num_de_pessoas); 

	// Alocando mem�ria
	struct dadinhos *pessoals = (struct dadinhos *)malloc(num_de_pessoas * sizeof(struct dadinhos));

	if (pessoals == NULL) // Verificando a mem�ria
	{
		printf("Erro na aloca��o de mem�ria!\n");
		exit(1);
	}

	// Preenchendo dados dos usu�rios
	for (n = 0; n < num_de_pessoas; n++)
	{
		printf("Pessoa %d:\n", n + 1);
		escreve(&pessoals[n]); // Chamando a fun��o escreve
	}

	// Exibindo informa��es
	for (n = 0; n < num_de_pessoas; n++)
	{
		printf("Descri��es do usu�rio(s) %d:\n", n + 1);
		imprime(&pessoals[n]); // Chamando a fun��o imprime

		// Pergunta se deseja alterar a idade
		char resposta;
		printf("Deseja atualizar sua idade no sistema? sim = 1 ou n�o = 2\n");
		scanf(" %c", &resposta);

		if (resposta == '1') 
		{
			alterar_idd(&pessoals[n]); // Chamando a fun��o alterar_idd 
		}
	}
	saber_quem_e(pessoals, num_de_pessoas); // Chamando a fun��o saber_quem_e

	// Liberando a mem�ria pufffffffffffffffffffff
	free(pessoals);
	return 0;
}
