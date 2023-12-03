#include <stdio.h>
#include <locale.h>
//Escreva uma função que receba dois números positivos por parâmetro e retorne a soma dos N números
//inteiros existentes entre eles.
//função declarada
int somainteiros(int Nmenor, int Nmaior)
{
	//inicialmete a resposta final é zero
	int resposta = 0;

	// Calcula a soma dos números inteiros entre os dois valores
	     //inicialização //condição // implemento
	for (Nmenor = Nmenor + 1; Nmenor < Nmaior; Nmenor++)
	{
		//irá gerar uma resposta pré definida, e vai somando até o némero menor não atender a condição
		resposta = resposta + Nmenor;
	}
// lembrando que a função será chamada em breve.
	return resposta;//retorno a resposta final.
}
int main()
{
	setlocale(LC_ALL, "Portuguese"); 
	int primario, secundario, maioral, minoral, soma = 0;
	printf("Insira dois números.\n");
	//leitura dos números
	scanf("%d", &primario);
    scanf("%d", &secundario);
    // O maior ou o menor?!
	if (primario > secundario)
	{
		maioral = primario;
		minoral = secundario;
	}
	if(primario < secundario)
	{
		maioral = secundario;
		minoral = primario;
	}
	else{
		printf("números iguais.\n");
	}
//declarar somatória chamando a função
	soma = somainteiros(minoral, maioral);//Associar valores.
//imprimir a soma.
printf("Declaração da resposta:\n");//no final imprime
	printf(" %d\n", soma);

}


