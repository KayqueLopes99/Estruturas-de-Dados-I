#include <stdio.h>
/*Questão 3) Qual será a saída exibida pelo programa a seguir:
Observe que, se int *p é uma variável do tipo ponteiro para inteiro, então int **pp é uma
variável do tipo ponteiro para ponteiro de inteiro, isto é, uma varável que poderá armazenar o
endereço de um ponteiro do tipo int. */
int main(void)
{
	int a, b, c, d; // variáveis introduzidas.
	int *p1;
	int *p2 = &a;//contéudo de p2 = endereço de A.
	int *p3 = &c;//contéudo de p3 = endereço de C.
	p1 = p2;     // p1 recebe o valor de p2..
	*p2 = 10; // p2 igual a 10.
	b = 20;  // b igual a 20.
	int **pp; //introdução do ponteiro armazenado dentro do ponteiro.
	pp = &p1; //pp do armazenamento é igual ao endereço de p1.
	*p3 = **pp; //conteúdo de p3 é igual ao endereço **pp.
	int *p4 = &d; //conteúdo de p4 é igual ao endereço de d.
	*p4 = b + (*p1)++;//incremento não conta no momento da soma.
//O contéudo de p4 é igual a operação a soma de b e o
//contéudo de p1 com imcremento.
	printf("%d\t%d\t%d\t%d\n", a, b, c, d);
//impressão.
//a é 11, pelo incremento em (*p1)++; de uma unidade.
//b é 20, pois já está definido.
//c é 10 pela igualdade entre variáveis.
//d é 30 na operação *p4 = b + (*p1)++;, sendo a soma de p1 + b, antes do incremento que não é contado aqui.
	return 0;
}
