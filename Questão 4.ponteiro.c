/*Questão 4) Crie um programa para calcular a área e o perímetro de um hexágono. O seu
programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
hexágono regular são dados, respectivamente, por:*/
#include <stdio.h>
#include <math.h>
#include <locale.h>
void calcula_hexagono(float l, float *area, float *perimetro)
{


	*area = (3 * pow(l, 2) * sqrt(3)) / 2;
	printf("O valor da área é %f.\n", *area);


	*perimetro = (6 * l);
	printf("O valor do perímetro é %2.f.\n", *perimetro);

}

int main()
{
	setlocale( LC_ALL, "portuguese" );
	float l;
	float area;
	float perimetro;

	// Entrada
	printf("Digite o lado do hexágono: ");
	scanf("%f", &l);

	// Chamar a função
	calcula_hexagono(l, &area, &perimetro);

	return 0;
}

/*Obs: Para os cálculos, utilize as funções sqrt e pow do módulo math da biblioteca
padrão de C. Em seguida, crie a função principal do programa e utilize a função
calcula_hexagono para calcular a área e o perímetro de um hexágono de lado l
informado pelo usuário.*/
