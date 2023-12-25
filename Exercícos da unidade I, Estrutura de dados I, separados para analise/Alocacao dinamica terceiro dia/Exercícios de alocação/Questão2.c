/*Quest�o 2) Escreva um programa para corrigir provas de m�ltipla escolha. Cada prova tem N
quest�es e cada quest�o vale 10/N pontos. Os primeiros dados a serem lidos s�o o n�mero de
quest�es e o gabarito da prova. Em seguida, ser�o lidas as respectivas respostas de um total de
10 alunos matriculados. Calcule e mostre:
a) a nota obtida para cada aluno;
b) a porcentagem de aprova��o, sabendo-se que a nota m�nima para ser aprovado �*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL , "portuguese");
	int N, quantidade; //Declara��o das vari�veis do n�mero de quest�es e da quantidade de alunos.
   int i, j;
	printf("Digite o n�mero de quest�es da prova da diciplina de ESTRUTURA DE DADOS I: \n");
	scanf("%d", &N);//scan para guardar
//aloca��o do gabarito.
	char *gabarito = (char *) calloc(N, sizeof(char));// Armazenar o gabarito

	if (gabarito == NULL)
	{
		printf("Erro na aloca��o dessa mem�ria!?\n");
		exit(1);
	}


	printf("Insira o gabarito\n");
	for (i = 0; i < N; i++)//percorer cada quest�o do gabarito.
	{
		printf("Quest�o %d: ", i + 1);//come�ar do primeiro = 1.
		scanf(" %c", &gabarito[i]);//armazenar no endere�o.

	}

	printf("Digite o n�mero de alunos: ");
	scanf("%d", &quantidade);// guardar o endere�o de quantidade.
	// Aloca��o de mem�ria das respostas dos alunos
	char *respostas_alunos = (char *)calloc(quantidade * N, sizeof(char));
	if (respostas_alunos == NULL)
	{
		printf("Erro na aloca��o de mem�ria!?\n");
		exit(1);
	}

	// Leitura das respostas dos alunos
	printf("\nDigite as respostas dos alunos:\n");
	// percorer o n�mero de alunos e lista-los
	for (i = 0; i < quantidade; i++)
	{
		printf("Aluno %d:\n", i + 1);


// percorer o n�mero de quest�es e lista-las
		for (j = 0; j < N; j++) // j � o respons�vel por percorrer o loop
		{
			printf("Quest�o %d: ", j + 1);//come�ar com 1. 
    
			scanf(" %c", &respostas_alunos[i * N + j]);
            // j � o n�mero do aluno com N sendo as quest�es e i as respostas.
			// Armazena a resposta no array `respostas_alunos` usando a f�rmula i * N + j.
		}
	}


	// Corre��o da prova e c�lculo da nota para cada aluno
	printf("\nResultados:\n");
	int aprovados = 0;// Vari�vel para contar os alunos aprovados, inicializando com 0.
	for (i = 0; i < quantidade; i++)
	{
		int nota = 0;// Vari�vel para armazenar as notas, inicializando com 0.
		for (j = 0; j < N; j++)
		{  // Loop para percorrer as quest�es.
			if (respostas_alunos[i * N + j] == gabarito[j])
			{
				nota += 10 / N; /// calculo da nota com modifica��o 
				// com 10 dividido pelo n�mero de quest�es na vari�vel N.
			}
		}

		printf("Aluno %d - Nota: %d\n", i + 1, nota);
// Exibe o n�mero do aluno e a sua nota.
		if (nota >= 6)
			//Verifica aprova��o com nota maior ou igual a 6.
		{
			aprovados++;
		}
	}
	printf("\nPorcentagem de Aprova��o: %3.f%%\n", (aprovados * 100.0) / quantidade);

	// Libera��o da mem�ria alocada
	free(gabarito);
	free(respostas_alunos);

	return 0;

}
