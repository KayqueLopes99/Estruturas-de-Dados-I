/* Escreva um programa para corrigir provas de múltipla escolha. Cada prova tem N
questões e cada questão vale 10/N pontos. Os primeiros dados a serem lidos são o número de
questões e o gabarito da prova. Em seguida, serão lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:
a) a nota obtida para cada aluno;
b) a porcentagem de aprovação, sabendo-se que a nota mínima para ser aprovado é 6.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL , "portuguese");
	int N, quantidade; //Declaração das varíaveis do número de questões e da quandidade de alunos.

	printf("Digite o número de questões da prova da diciplina de ESTRUTURA DE DADOS I: \n");
	scanf("%d", &N);//scan para guardar
//alocação do gabarito.
	char *gabarito = (char *) calloc(N, sizeof(char));// Armazenar o gabarito

	if (gabarito == NULL)
	{
		printf("Erro na alocação dessa memória!?\n");
		exit(1);
	}


	printf("Insira o gabarito\n");
	for (int i = 0; i < N; i++)//percorer cada questão do gabarito.
	{
		printf("Questão %d: ", i + 1);//começar do primeiro = 1.
		scanf(" %c", &gabarito[i]);//armazenar no endereço.

	}

	printf("Digite o número de alunos: ");
	scanf("%d", &quantidade);// guardar o endereço de quantidade.
	// Alocação de memória das respostas dos alunos
	char *respostas_alunos = (char *)calloc(quantidade * N, sizeof(char));
	if (respostas_alunos == NULL)
	{
		printf("Erro na alocação de memória!?\n");
		exit(1);
	}

	// Leitura das respostas dos alunos
	printf("\nDigite as respostas dos alunos:\n");
	// percorer o número de alunos e lista-los
	for (int i = 0; i < quantidade; i++)
	{
		printf("Aluno %d:\n", i + 1);


// percorer o número de questões e lista-las
		for (int j = 0; j < N; j++) // j é o responsável por percorrer o loop
		{
			printf("Questão %d: ", j + 1);//começar com 1. 
    
			scanf(" %c", &respostas_alunos[i * N + j]);
            // j é o número do aluno com N sendo as questões e i as respostas.
			// Armazena a resposta no array `respostas_alunos` usando a fórmula i * N + j.
		}
	}


	// Correção da prova e cálculo da nota para cada aluno
	printf("\nResultados:\n");
	int aprovados = 0;// Variável para contar os alunos aprovados, inicializando com 0.
	for (int i = 0; i < quantidade; i++)
	{
		int nota = 0;// Variável para armazenar as notas, inicializando com 0.
		for (int j = 0; j < N; j++)
		{  // Loop para percorrer as questões.
			if (respostas_alunos[i * N + j] == gabarito[j])
			{
				nota += 10 / N; /// calculo da nota com modificação 
				// com 10 dividido pelo número de questões na varíavel N.
			}
		}

		printf("Aluno %d - Nota: %d\n", i + 1, nota);
// Exibe o número do aluno e a sua nota.
		if (nota >= 6)
			//Verifica aprovação com nota maior ou igual a 6.
		{
			aprovados++;
		}
	}
	printf("\nPorcentagem de Aprovação: %3.f%%\n", (aprovados * 100.0) / quantidade);

	// Liberação da memória alocada
	free(gabarito);
	free(respostas_alunos);

	return 0;

}
