/*Questão 1) Uma empresa fez uma pesquisa para saber se as pessoas gostaram ou não de um
novo produto. Um número N de pessoas de ambos os sexos foi entrevistado, e o questionário
consistia em apenas duas perguntas: (i) o sexo do entrevistado (M/F) e (ii) sua opinião sobre o
produto (gostou/não gostou). Escreva um programa em C que:
a) leia as respostas contidas no questionário e armazene-as em dois arrays vinculados,
um deles contendo a resposta para a primeira pergunta e o outro contendo a resposta
para a segunda pergunta.
b) determine a porcentagem de pessoas do sexo feminino que responderam que
gostaram do produto.
c) determine a porcentagem de pessoas do sexo masculino que responderam que não
gostaram do produto.*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main()
{
	setlocale(LC_ALL , "portuguese");
	int i, N; // Declaração da varíaveis N = tamanho e i para as respostas.
	int mulher_gosta = 0; //incializando com zero.
	int homem_nao_gosta = 0;
	printf("Digite o número de pessoas entrevistadas, por gentileza: ");
	scanf("%d", &N);//Guardei o tamanho no endereço.
//alocação das respostas sexo e opiniao.
	char *sexo = (char *) malloc(N * sizeof(char));
	char *opiniao = (char *) malloc(N * sizeof(char));

	if (sexo == NULL || opiniao == NULL)
	{
		printf("Erro na alocação dessa memória.\n");
		exit(1);
	}

	i = 0;// inicializei com i = 0 para quando contar o número de pessoas começar em 1.
	do
	{
		printf("Entrevistado %d:\n", i + 1);
		printf("Primeira pergunta valendo 1000 mil!!!:\n qual é seu gênero?\n Masculino = m \nfeminino = f\n");
		scanf(" %c", &sexo[i]); // endereço para primeira resposta.

		printf("Segunda pergunta valendo 1000 mil!!!:\n qual a sua opinião sobre o produto querido(a)\n Gostou = g\n Não gostou = n\n");
		scanf(" %c", &opiniao[i]); // endereço para segunda pergunta.

		if((sexo[i] != 'f' && sexo[i] != 'm') || (opiniao[i] != 'g' && opiniao[i] != 'n'))
		{// Associação as resposta as letras correspondentes.
			printf("Erro nas respostas\n");// Caso de erro.
		}
		else
		{
			// Contar mulheres que gostaram.
			if (sexo[i] == 'f' && opiniao[i] == 'g')
			{
				mulher_gosta++;

			}
            // Contar homens que não gostaram.
			else if (sexo[i] == 'm' && opiniao[i] == 'n')
			{
				homem_nao_gosta++;

			}
			i++; // incrementa o i até atender a codição para passar para próxima entrevista.
		}
		// Verificar se as respostas são válidas.
	}
	while ( i < N); // loop while para repetir enquanto i não for  =  N e ficar correto.

	if (N > 0)// Se o tamanho é maior que zero antes de proseguir.
	{
		printf("\nPorcentagem de mulheres que gostaram do produto: %.2f%%\n", (mulher_gosta * 100.0f) / N);
		printf("\nPorcentagem de homens que não gostaram do produto: %.2f%%\n", (homem_nao_gosta * 100.0f) / N);
// print'sf para já imprimir direto o resultado.
	}
// Liberar puffffffffff
	free(sexo);
	free(opiniao);
return 0;
}
