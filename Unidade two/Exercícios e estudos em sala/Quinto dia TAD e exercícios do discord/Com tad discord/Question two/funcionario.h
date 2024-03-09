#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <stdio.h>
// Coloquei a struct para testar essa maneira 
// Struct.
typedef struct funcionario
{
 int funcional;
 char nome[25];
 char departamento;
 float salario;
} Funcionario;

// Protótipo da função copia_dados
void copia_dados(FILE *fl, int n, Funcionario** pessoal);

// Protótipo da função imprime_folha
void imprime_folha(int n, Funcionario** pessoal, char depto);

#endif
