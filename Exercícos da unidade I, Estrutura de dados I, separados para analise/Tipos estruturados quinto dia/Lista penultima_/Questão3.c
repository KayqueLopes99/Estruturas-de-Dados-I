/*Escreva um programa que implementa uma struct Data com os campos dia, mes e ano. O mes deve
ser armazenado como um enum com os valores JANEIRO, FEVEREIRO, MARCO, ABRIL, MAIO,
JUNHO, JULHO, AGOSTO, SETEMBRO, OUTUBRO, NOVEMBRO e DEZEMBRO. O programa
deve ler a data e imprimir a data no formato dd/mm/aaaa.*/

#include <stdio.h>
#include <stdlib.h>

// Definindo um enum para os meses
typedef enum mes
{
    janeiro = 1, fevereiro = 2, marco = 3, abril = 4, maio = 5, junho = 6, 
    julho = 7, agosto = 8, setembro = 9, outubro = 10, novembro = 11, dezembro = 12
} Mes;


// Definindo uma struct para a data
typedef struct data
{
	int dia, ano;
	Mes armazenamento_mes; // O mês é armazenado como um enum
} Data;

// Função para preencher e imprimir a data
void preenche_imprime(Data *data)
{
	printf("Digite o dia: \n");
	scanf("%d", &data->dia);
	printf("Digite o mês:  \n");
	scanf("%d", (int*)&data->armazenamento_mes); // Lê o mês como um int e armazena como um enum
	printf("Digite o ano:  \n");
	scanf("%d", &data->ano);

    // Imprime o nome do mês com base no valor do enum
	switch(data->armazenamento_mes)
	{
	case janeiro:
		printf("Mês: Janeiro\n");
		break;
	case fevereiro:
		printf("Mês: Fevereiro\n");
		break;
	case marco:
		printf("Mês: Março\n");
		break;
	case abril:
		printf("Mês: Abril\n");
		break;
	case maio:
		printf("Mês: Maio\n");
		break;
	case junho:
		printf("Mês: Junho\n");
		break;
	case julho:
		printf("Mês: Julho\n");
		break;
	case agosto:
		printf("Mês: Agosto\n");
		break;
	case setembro:
		printf("Mês: Setembro\n");
		break;
	case outubro:
		printf("Mês: Outubro\n");
		break;
	case novembro:
		printf("Mês: Novembro\n");
		break;
	case dezembro:
		printf("Mês: Dezembro\n");
		break;
	default:
		printf("Mês inválido\n");
		break;
	}

    // Imprime a data no formato dd/mm/aaaa
	printf("dia %d / mês %d / ano %d", data->dia, data->armazenamento_mes, data->ano);
}

int main(void)
{
	Data data;
	preenche_imprime(&data); // Chama a função para preencher e imprimir a data
	return 0;
}
