/*
Questão 3) Defina estruturas para representar retângulos (dadas a base e a altura) e círculos (dado o raio), e
implemente as funções a seguir:
a) Dado um círculo, crie e retorne o maior retângulo circunscrito de altura h. Considere que h é menor do
que o diâmetro do círculo.
Protótipo: Ret* ret_circunscrito(Circ* c, float h);
b) Dado um retângulo, crie e retorne o maior círculo interno ao retângulo.
Protótipo: Circ* circ_interno(Ret* r);
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar um retângulo
typedef struct
{
	float base;
	float altura;
} Retangulichu;

// Estrutura para representar um circulo
typedef struct
{
	float raio;
} Circulichu;

// Função para calcular as dimensões de um retângulo circunscrito em um circulo dado
Retangulichu* ret_circunscrito(Circulichu* c, float h)
{
	Retangulichu* r = (Retangulichu*) malloc(sizeof(Retangulichu));
	r->altura = h; // Atribui a altura do retângulo
	// formula do retângulo 
	r->base = (2 * sqrt(pow(c->raio, 2) - (pow(h / 2, 2))));
	return r; // Retorna o retângulo calculado
}

// Função para calcular o raio de um circulo inscrito em um retângulo dado
Circulichu* circ_interno(Retangulichu* r)
{
	Circulichu* c = (Circulichu*) malloc(sizeof(Circulichu));
	// Calcula o raio do circulo como metade da menor dimensão do retângulo
	c->raio = ((r->base < r->altura ? r->base : r->altura) / 2);
	return c; // Retorna o circulo calculado
}

int main()
{
	float raio, altura, base;

	printf("==== O que voce deseja calcular ====\n");
	printf("====  -  retangulo circunscrito ====\n");
	printf("====  -     Circulo interno     ====\n");

	// Solicita ao usuario o raio do circulo e a altura do retangulo
	printf("Insira o raio do circulo: \n");
	scanf("%f", &raio);
	printf("Insira a altura 'h' para o retângulo circunscrito: \n");
	scanf("%f", &altura);

	// Calcula e imprime as dimensções do retângulo circunscrito
	Circulichu c = {raio};
	Retangulichu* r = ret_circunscrito(&c, altura);
	printf("O ret�ngulo circunscrito\n Base: %.2f\n Altura %.2f\n", r->base, r->altura);

	// Solicita ao usuario a base e a altura do retângulo
	printf("Insira a base do retangulo: ");
	scanf("%f", &base);
	printf("Insira a altura do retangulo:");
	scanf("%f", &altura);

	// Calcula e imprime o raio do circulo inscrito
	Retangulichu r2 = {base, altura};
	Circulichu* c2 = circ_interno(&r2);
	printf("O circulo interno tem raio: %.2f\n", c2->raio);

	return 0;
}

