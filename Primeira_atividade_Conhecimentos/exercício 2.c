#include <stdio.h>
#include <locale.h>
int main(){
// O que faz o seguinte programa? E qual sua saida?
/*#include <stdio.h>
int f (int mat [3][3]) {
return ( mat [0][0]* mat [1][1]* mat [2][2]) + ( mat [0][1]* mat [1][2]* mat [2][0]) + (
mat [0][2]* mat [1][0]* mat [2][1]) - ( mat [0][1]* mat [0][1]* mat [2][2]) - ( mat
[0][0]* mat [1][2]* mat [2][1]) - ( mat [0][2]* mat [1][1]* mat [2][0]) ;
}
int main ( void ) {
int m [3][3]={{0 ,1 ,0} ,{3 ,1 , -1} ,{4 ,0 ,1}};
int de = f ( m ) ;
printf (" Resultado = \t %d", de ) ;
return 0;
}*/
	setlocale(LC_ALL, "Portuguese");

	printf("RESOLUÇÃO DA QUESTÃO 2");
printf("As linhas e colunas estão na matriz nos parâmetros da função, fazendo retorno\n");
printf("com operações nas posições da matriz, logo no  int main() temos uma matriz que é\n");
printf("o resultado pré-definido das posições, substituindo na operação cada posição pelo seu\n");
printf("número correspondente temos que o resultado é -5\n");

	return 0;
}