/*
 questão 2) Escreva um programa em C que manipula dados de um conjunto de alunos da disciplina de Estrutura de
Dados e Programação da UFERSA Pau dos Ferros. Para representar um aluno são necessárias as seguintes
informações: matrícula (inteiro), nome (80 caracteres), turma (caractere), três notas (reais em um vetor) e uma
média (real). Seu programa deve levar em consideração que é ofertado um número máximo de vagas para a
disciplina. Sabendo dessas informações, faça o que se pede nos itens a seguir:
a) Implemente uma função que recebe os dados de um aluno e o matricula na disciplina, caso haja vaga
disponível. Protótipo: void matricula(int n,Aluno** alunos);
b) Implemente uma função que lança as notas e calcula a média dos alunos da disciplina. Protótipo: void
lanca_notas(int n, Aluno** alunos);
c) Implemente uma função que imprime os dados de todos os alunos da disciplina. Protótipo: void
imprime_tudo(int n, Aluno** alunos);
d) Implemente uma função que imprime os dados de todos os alunos de uma turma. Protótipo: void
imprime_turma(int n, Aluno** alunos, char turma);
e) Implemente uma função que imprime os alunos aprovados de uma determinada turma. Para ser
aprovado, o aluno deve ter média maior que ou igual a 7,0. Protótipo: void imprime_turma_aprovados(int n,
Aluno**alunos, char turma);
Sugestões: i) Use um vetor de ponteiros para estrutura; ii) Use uma constante simbólica para representar o número
máximo de alunos. Iii) Antes de manipular o vetor de ponteiros, inicialize cada um de seus elementos com NULL
(você pode escrever uma função para isso).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Estrutura Aluno
typedef struct
{
	int matricula;
	char nome[80];
	char turma;
	float notas[3];
	float media;
} Aluno;

// Função para matricular alunos.
void matricula(Aluno** alunos, int maximo_alunos, Aluno* novatooo)
{
	int i;

	// Loop para matricular cada aluno.
	for(i = 0; i < maximo_alunos; i++)
	{
		novatooo = (Aluno*) malloc(sizeof(Aluno)); // Aloca memória para um novo aluno.
		printf("Digite a matricula do aluno %d\n", i + 1);
		scanf("%d", &novatooo->matricula);
		printf("Digite o nome do aluno: \n");
		scanf(" %[^\n]", novatooo->nome);
		printf("Digite a turma do aluno: a ou b?\n");
		scanf(" %c", &novatooo->turma);

		alunos[i] = novatooo; // Adiciona o novo aluno ao array de alunos.

		printf("Matrícula realizada com sucesso.\n");
	}
	system("cls");
}

// Função para lançar as notas.
void lanca_notas(Aluno** alunos, int maximo_alunos, Aluno* novatooo)
{
	int i;
	for(i = 0; i < maximo_alunos; i++)
	{
		printf("Aluno %d\n", i + 1);
		printf("Nota 1: ");
		scanf("%f", &alunos[i]->notas[0]);
		printf("Nota 2: ");
		scanf("%f", &alunos[i]->notas[1]);
		printf("Nota 3: ");
		scanf("%f", &alunos[i]->notas[2]);
		alunos[i]->media = ((alunos[i]->notas[0] + alunos[i]->notas[1] + alunos[i]->notas[2]) / 3); // Calcula a média das notas.
		printf("Média do aluno: %.2f \n", alunos[i]->media);
		if(alunos[i]->media >= 7)
		{
			printf("Aprovado!\n");
		}
		else
		{
			printf("Reprovado!\n");
		}
	}
	system("cls");
}

// Função para imprimir.
void imprime_tudo(Aluno** alunos, int maximo_alunos, Aluno* novatooo)
{
	int i;
	for(i = 0; i < maximo_alunos; i++)
	{
		printf("Dados do aluno %d\n", i + 1);
		printf("Matrícula: %d\n", alunos[i]->matricula);
		printf("Nome: %s\n", alunos[i]->nome);
		printf("Turma: %c\n", alunos[i]->turma);

		printf("Notas do aluno %d\n", i + 1);
		printf("Nota 1: %2.f\n", alunos[i]->notas[0]);// novatooo acessar a nota[n].
		printf("Nota 2: %2.f\n", alunos[i]->notas[1]);
		printf("Nota 3: %2.f\n", alunos[i]->notas[2]);
		printf("Média: %.2f \n", alunos[i]->media);
		if(alunos[i]->media >= 7)
		{
			printf("Situação: Aprovado!\n");
		}
		else
		{
			printf("Situação: Reprovado!\n");
		}
	}
	system("pause");
	system("cls");
}

// Função para imprimir.
void imprime_turma(Aluno** alunos, int maximo_alunos, char turma)
{
	int i;
	int tem_aluno_aqui = 0;
	printf("Alunos da turma %c:\n", turma);
	for(i = 0; i < maximo_alunos; i++)
	{
		if(alunos[i]->turma == turma) // Verifica se o aluno pertence à turma.
		{
			tem_aluno_aqui = 1;
			printf("Aluno número %d\n", i + 1);
			printf("Matrícula: %d\n", alunos[i]->matricula);
			printf("Nome: %s\n", alunos[i]->nome);
			printf("Turma: %c\n", alunos[i]->turma);
			printf("Nota 1: %2.f\n", alunos[i]->notas[0]);
			printf("Nota 2: %2.f\n", alunos[i]->notas[1]);
			printf("Nota 3: %2.f\n", alunos[i]->notas[2]);
		}
	}
	if(tem_aluno_aqui == 0)
	{
		printf("Não há alunos na turma %c logo sem alunos aprovados e reprovados.\n", turma);
	}
}

// Função para imprimir os aprovados.
void imprime_aprovados(Aluno** alunos, int maximo_alunos, char turma)
{
	int i;
	printf("Alunos aprovados da turma %c:\n", turma);
	for(i = 0; i < maximo_alunos; i++)
	{
		if(alunos[i]->turma == turma && alunos[i]->media >= 7) // Verifica se foi aprovado.
		{
			printf("Aluno número %d\n", i + 1); // deixar bonito com aluno 'n'.
			printf("Nome: %s\n", alunos[i]->nome);// alunos[i] acessa os dados.
			printf("Turma: %c\n", alunos[i]->turma);
			printf("Média: %.2f \n", alunos[i]->media);
			printf("Situação: Aprovado!\n");
		}
	}
}


int main()
{
	setlocale(LC_ALL, "");
	// Cada loop serve para a contagem de alunos ficar certa.
	// Tipo tem três alunos, assim cada loop vai se repetir para cada um dos alunos.
	int maximo_alunos;

	printf("Vagas disponíveis. Digite por gentileza: \n");
	scanf("%d", &maximo_alunos);
	while(maximo_alunos <= 0)
	{
		printf("Erro: número de vagas inválido.\n");
		printf("Vagas disponíveis. Digite por gentileza: \n");
		scanf("%d", &maximo_alunos);
	}

	Aluno** alunos = (Aluno**) malloc(maximo_alunos * sizeof(Aluno*)); // Aloca memória para o array de alunos
	Aluno* novatooo = (Aluno*) malloc(sizeof(Aluno)); // Aloca memória para um novo aluno
	// Chamadas de funções.
	matricula(alunos, maximo_alunos, novatooo); // Matricula os alunos
	lanca_notas(alunos, maximo_alunos, novatooo); // Lança as notas dos alunos
	imprime_tudo(alunos, maximo_alunos, novatooo); // Imprime os dados de todos os alunos
	imprime_turma(alunos, maximo_alunos, 'a'); // Imprime os dados dos alunos da turma 'a'
	imprime_aprovados(alunos, maximo_alunos, 'a'); // Imprime os alunos aprovados da turma 'a'
	imprime_turma(alunos, maximo_alunos, 'b'); // Imprime os dados dos alunos da turma 'b'
	imprime_aprovados(alunos, maximo_alunos, 'b'); // Imprime os alunos aprovados da turma 'b'

}

