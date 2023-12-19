#include <stdio.h>
#include <locale.h>

//Funções das operações! com retornos!
int soma(int a, int b)
{
	return a + b;
}

int subtracao(int a, int b)
{
	return a - b;
}
int multiplicacao(int a, int b)
{
	return a * b;
}
int divisao(int a, int b)
{
	return a / b;
}
// Funçõo que realiza a operaçõo escolhida, passando a e b para x e y.
int calcula(int x, int y, int (*operacao)(int, int))
{
	return operacao(x, y);
}
int main(){
setlocale(LC_ALL, "portuguese");

int operacao;
int a;
int b;
    printf("Insira o primeiro número: \n");
    scanf("%d", &a);
    printf("Insira o segundo número: \n");
    scanf("%d", &b);
    printf("Digite o número da operação (1 a 4):\n");
    printf("====================================\n");
    printf("=========== 1 - adição =============\n");
    printf("========== 2 - Subtração ===========\n");
    printf("======= 3 - multiplicação ==========\n");
    printf("========== 4 - divisão =============\n");
    printf("====================================\n");
    scanf("%d", &operacao);
    switch (operacao) {

    case 1:
        printf("Adição: \n");
        // Chama a funçõo calcula, passando a função soma como argumento e as 
        //demais caso sejam escolhidas.
        printf("Resultado: %d", calcula(a, b, soma));
        break;
    case 2:
        printf("Subtração: \n");
        printf("Resultado: %d", calcula(a, b, subtracao));
        break;
    case 3:
        printf("Multiplição: \n");
        printf("Resultado: %d", calcula(a, b, multiplicacao));
        break;
    case 4:
        printf("Divisão: \n");
        printf("Resultado: %d", calcula(a, b, divisao));
        break;
    default:
        printf("Opção invalida \n");
    }
    return 0;
}

