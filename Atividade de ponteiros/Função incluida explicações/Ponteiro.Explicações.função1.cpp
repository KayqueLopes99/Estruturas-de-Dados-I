#include <stdio.h>
#include <locale.h>

void incrementa(int *ponteiro)//função incrementa com parâmetros ponteiro.
{
	(*ponteiro)++;//incremento de uma unidade ao ponteiro.
}

int main()
{
	setlocale(LC_ALL, "portuguese");
	int variavel = 5; //Declaração da varíavel e atribuição do valor 5.
	//igual a 5.
	incremento(&variavel);//Passa o endereço da variável para a função incrementa.
	//do ponteiro.
	printf("Valor da varíavel: %d", variavel);//Imprime o resultado.

	return 0;
}
