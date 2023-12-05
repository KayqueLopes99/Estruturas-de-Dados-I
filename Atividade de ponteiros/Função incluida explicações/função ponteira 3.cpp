#include <stdio.h>
#include <locale.h>

//Fun��es das opera��es! com retornos!
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
// Fun��o que realiza a opera��o escolhida, passando a e b para x e y.
int calcula(int x, int y, int (*operacao)(int, int))
{
	return operacao(x, y);
}
int main(){
setlocale(LC_ALL, "portuguese");

int operacao;
int a;
int b;
    printf("Insira o primeiro n�mero: \n");
    scanf("%d", &a);
    printf("Insira o segundo n�mero: \n");
    scanf("%d", &b);
    printf("Digite o n�mero da opera��o (1 a 4):\n");
    printf("====================================\n");
    printf("=========== 1 - adi��o =============\n");
    printf("========== 2 - Subtra��o ===========\n");
    printf("======= 3 - multiplica��o ==========\n");
    printf("========== 4 - divis�o =============\n");
    printf("====================================\n");
    scanf("%d", &operacao);
    switch (operacao) {

    case 1:
        printf("Adi��o: \n");
        // Chama a fun��o calcula, passando a fun��o soma como argumento e as 
        //demais caso sejam escolhidas.
        printf("Resultado: %d", calcula(a, b, soma));
        break;
    case 2:
        printf("Subtra��o: \n");
        printf("Resultado: %d", calcula(a, b, subtracao));
        break;
    case 3:
        printf("Multiplica��o: \n");
        printf("Resultado: %d", calcula(a, b, multiplicacao));
        break;
    case 4:
        printf("Divis�o: \n");
        printf("Resultado: %d", calcula(a, b, divisao));
        break;
    default:
        printf("Op��o inv�lida \n");
    }
    return 0;
}

