/*Questão 4) Crie um programa para calcular a área e o perímetro de um hexágono. O seu
programa deve implementar uma função chamada calcula_hexagono que calcula a área e o
perímetro de um hexágono regular de lado l. A função deve obedecer ao seguinte protótipo:
void calcula_hexagono(float l, float *area, float *perimetro); A área e o perímetro de um
hexágono regular são dados, respectivamente, por:*/
#include <stdio.h>
#include <math.h>
/*A biblioteca "math.h" fornece funções matemáticas em C, como cálculos trigonométricos, exponenciais,
logarítmicos e outras operações matemáticas. Ela é amplamente usada para realizar cálculos complexos em programas em C.*/
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


/*Informações básicas:
os comandos da biblioteca "math.h" e suas respectivas descrições:

- sin(): Calcula o seno de um ângulo.
- cos(): Calcula o cosseno de um ângulo.
- tan(): Calcula a tangente de um ângulo.
- exp(): Calcula a exponencial (elevado à potência) de um número.
- log(): Calcula o logaritmo natural de um número.
- sqrt(): Calcula a raiz quadrada de um número.
- pow(): Calcula a potência de um número elevado a outro número.
- ceil(): Arredonda um número para cima para o inteiro mais próximo.
- floor(): Arredonda um número para baixo para o inteiro mais próximo.
- fabs(): Retorna o valor absoluto (módulo) de um número.
- fmod(): Calcula o resto da divisão entre dois números. */
