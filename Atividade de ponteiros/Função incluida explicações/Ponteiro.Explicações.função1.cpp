#include <stdio.h>
#include <locale.h>

void incrementa(int *ponteiro)//fun��o incrementa com par�metros ponteiro.
{
	(*ponteiro)++;//incremento de uma unidade ao ponteiro.
}

int main()
{
	setlocale(LC_ALL, "portuguese");
	int variavel = 5; //Declara��o da var�avel e atribui��o do valor 5.
	//igual a 5.
	incremento(&variavel);//Passa o endere�o da vari�vel para a fun��o incrementa.
	//do ponteiro.
	printf("Valor da var�avel: %d", variavel);//Imprime o resultado.

	return 0;
}
