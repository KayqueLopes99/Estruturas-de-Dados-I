/*
2. Crie um tipo estruturado para armazenar dados de uma pessoa. Uma estrutura deste tipo possui os seguintes campos: nome da pessoa, número do documento e idade.
a) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e preencha seus campos com valores fornecidos pelo usuário via teclado.
b) Escreva uma função que receba como parâmetro o endereço de uma estrutura do tipo Pessoa e imprima os valores dos seus campos.
c) Implemente uma função para realizar uma atualização da idade de uma estrutura do tipo Pessoa.
d) Escreva uma função que receba como parâmetro um vetor de estruturas do tipo Pessoa e imprima o nome da Pessoa mais velha e mais nova.*/
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

// Função para preencher os dados do usuário
void escreve(struct dadinhos *pessoal)
{
	printf("Digite o nome do usuário:\n");
	scanf("%s", pessoal->nome); 
	printf("Digite o número do documento:\n");
	scanf("%d", &pessoal->numero_documento); 
	printf("Digite a sua idade:\n");
	scanf("%d", &pessoal->idade); 
}

// Função para imprimir os dados do usuário
void imprime(struct dadinhos *pessoal)
{
	printf("O nome do senhor(a): %s\n", pessoal->nome); // Imprimindo o nome 
	printf("Número correspondente ao seu documento: %d\n", pessoal -> numero_documento); // Imprimindo o número do documento
	printf("Sua idade no sistema: %d\n", pessoal->idade); // Imprimindo a idade
	printf("\n");
}
// Função para alterar a idade
void alterar_idd(struct dadinhos *pessoal){
	printf("Atualização de idade do senhor(a): \n");
	printf("Digite a nova idade para atualização %s:\n", pessoal->nome); 
	scanf("%d", &pessoal->idade);
	printf("Idade atualizada com extremo sucesso !!!!!!!!!!\n Idade atual:  %d\n:", pessoal->idade); // Imprimindo a nova idade 
}

// Função para encontrar o usuário mais velho e mais novo
void saber_quem_e(struct dadinhos pessoals[], int tamanho) {
	int i;
	int velho = 0, novo = 0; // Inicializando as variáveis velho e novo
	for (i = 1; i < tamanho; i++) {
		if (pessoals[i].idade > pessoals[velho].idade) { // Se a idade do usuário atual é maior que a idade do usuário mais velho
			velho = i; 
		}
		if (pessoals[i].idade < pessoals[novo].idade) { // Se a idade do usuário atual é menor que a idade do usuário mais novo
			novo = i; 
		}
	}
	printf("usuário %s com muita idade :\n", pessoals[velho].nome); // Imprimindo o nome do usuário mais velho
	printf("idade: %d\n", pessoals[velho].idade); // Imprimindo a idade do usuário mais velho
	printf("usuário %s mais novo :\n", pessoals[novo].nome); // Imprimindo o nome do usuário mais novo
	printf("idade: %d\n ", pessoals[novo].idade); // Imprimindo a idade do usuário mais novo
}

int main()
{
	setlocale(LC_ALL, "portuguese"); 
	int num_de_pessoas;
int n;
	printf("Quantas cidadãos o senhor(a) deseja cadastrar: ");
	scanf("%d", &num_de_pessoas); 

	// Alocando memória
	struct dadinhos *pessoals = (struct dadinhos *)malloc(num_de_pessoas * sizeof(struct dadinhos));

	if (pessoals == NULL) // Verificando a memória
	{
		printf("Erro na alocação de memória!\n");
		exit(1);
	}

	// Preenchendo dados dos usuários
	for (n = 0; n < num_de_pessoas; n++)
	{
		printf("Pessoa %d:\n", n + 1);
		escreve(&pessoals[n]); // Chamando a função escreve
	}

	// Exibindo informações
	for (n = 0; n < num_de_pessoas; n++)
	{
		printf("Descrições do usuário(s) %d:\n", n + 1);
		imprime(&pessoals[n]); // Chamando a função imprime

		// Pergunta se deseja alterar a idade
		char resposta;
		printf("Deseja atualizar sua idade no sistema? sim = 1 ou não = 2\n");
		scanf(" %c", &resposta);

		if (resposta == '1') 
		{
			alterar_idd(&pessoals[n]); // Chamando a função alterar_idd 
		}
	}
	saber_quem_e(pessoals, num_de_pessoas); // Chamando a função saber_quem_e

	// Liberando a memória pufffffffffffffffffffff
	free(pessoals);
	return 0;
}
