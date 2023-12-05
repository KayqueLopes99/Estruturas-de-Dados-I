//=========== Explicações e entendimentos ================//

/*#include <stdio.h>

int main(void) {
    int x, y; //variáveis.
    y = 2; //atribuição de 2 a y.
    int *p1, //*p2; Ponteiros.
    p1 = &y; //Endereço de  y atribuido a p1.
    x = 1; // atribuição de 1.
    p2 = p1; // contéudo de p1 = p2.
    (*p1)++; // incremento
    printf("%d %d", x, y);

    return 0;
}*/
//(*p1)++:  o valor apontado por p1 é incrementado após a operação de desreferenciamento,
//ou seja, numa conta n = i + (*p1)++. sendo i = 2, (*p1) = 5, o resultado não será 8 e sim 7.
//E sim somente no valor imprimido de p1 que será 6 com o incremento.
//*p1++: Neste caso, significa que o valor apontado por p1 é obtido primeiro, ou seja, ele faz somente a soma normal
//sem atribuições por enquanto.
//e em seguida, o ponteiro p1 é incrementado.
//++p1 atribui a incremento na operação e no ponteiro.
//n = i + (*p1)++. sendo i = 2, (*p1) = 5, logo o resultado será 8

/*EXEMPLOS DADO EM AULA.
#include <stdio.h>

int inc (int num) {

	return(++num);

}
int main(void){
	int numero = 5;
	numero = inc(numero);

	printf("%d", numero);
	return 0;
}*/

/* int *cria_variavel() {
	int variavel = 5;

	return &variavel;
	}

	int main(){
		int *ponteiro = cria_variavel ();
		printf("Valor da variavel: %d", *ponteiro);
		return 0;

	}
*/
#include <stdio.h>

void incremento (int *ponteiro)
{

	(*ponteiro)++;
}

int main()
{
	int variavel = 5;

	incremento(&variavel);
	printf("Valor da variavel: %d", variavel);
	return 0;
}
