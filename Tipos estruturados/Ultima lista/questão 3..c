#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Estrutura para representar um ret�ngulo
typedef struct
{
	float base;
	float altura;
} Retangulichu;

// Estrutura para representar um c�rculo
typedef struct
{
	float raio;
} Circulichu;

// Fun��o para calcular as dimens�es de um ret�ngulo circunscrito em um c�rculo dado
Retangulichu* ret_circunscrito(Circulichu* c, float h)
{
	Retangulichu* r = (Retangulichu*) malloc(sizeof(Retangulichu));
	r->altura = h; // Atribui a altura do ret�ngulo
	// formula do ret�ngulo 
	r->base = (2 * sqrt(pow(c->raio, 2) - (pow(h / 2, 2))));
	return r; // Retorna o ret�ngulo calculado
}

// Fun��o para calcular o raio de um c�rculo inscrito em um ret�ngulo dado
Circulichu* circ_interno(Retangulichu* r)
{
	Circulichu* c = (Circulichu*) malloc(sizeof(Circulichu));
	// Calcula o raio do c�rculo como metade da menor dimens�o do ret�ngulo
	c->raio = ((r->base < r->altura ? r->base : r->altura) / 2);
	return c; // Retorna o c�rculo calculado
}

int main()
{
	float raio, altura, base;

	printf("==== O que voc� deseja calcular ====\n");
	printf("====  - ret�ngulo circunscrito ====\n");
	printf("====  -    C�rculo interno     ====\n");

	// Solicita ao usu�rio o raio do c�rculo e a altura do ret�ngulo
	printf("Insira o raio do c�rculo: \n");
	scanf("%f", &raio);
	printf("Insira a altura 'h' para o ret�ngulo circunscrito: \n");
	scanf("%f", &altura);

	// Calcula e imprime as dimens�es do ret�ngulo circunscrito
	Circulichu c = {raio};
	Retangulichu* r = ret_circunscrito(&c, altura);
	printf("O ret�ngulo circunscrito\n Base: %.2f\n Altura %.2f\n", r->base, r->altura);

	// Solicita ao usu�rio a base e a altura do ret�ngulo
	printf("Insira a base do ret�ngulo: ");
	scanf("%f", &base);
	printf("Insira a altura do ret�ngulo:");
	scanf("%f", &altura);

	// Calcula e imprime o raio do c�rculo inscrito
	Retangulichu r2 = {base, altura};
	Circulichu* c2 = circ_interno(&r2);
	printf("O c�rculo interno tem raio: %.2f\n", c2->raio);

	return 0;
}

