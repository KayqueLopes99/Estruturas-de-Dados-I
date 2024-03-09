#include <stdio.h>

struct ponto{
	float x, y;
};

void imprime (struct ponto *pp) {
	printf("O ponto fornecido foi: (%.2f, %.2f)\n", pp->x, pp->y);
}
void captura (struct ponto *pp) {
	printf("Digite as coordenadas do ponto (x,y):");
	scanf("%f %f", &pp->x, &pp->y);
}

int main(void){
	struct ponto p;
	captura(&p);
	imprime(&p);
	return 0;
}