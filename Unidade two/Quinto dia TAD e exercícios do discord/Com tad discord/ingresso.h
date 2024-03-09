#ifndef INGRESSO_H
#define INGRESSO_H

typedef struct {
	float preco;
	char local[50];
	char atracao[50];	
	
}Ingresso;

void preenche(int num_eventos, Ingresso* i);
void imprime(int num_eventos, Ingresso* i);
void altera_preco(Ingresso* i, float valor);
void imprime_menor_maior_preco(int num_eventos, Ingresso* i);

#endif