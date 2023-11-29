#include <stdio.h>
#include <locale.h>
//3.Identifique os erros de compilação que seriam detectados no seguinte programa se eles existirem:
/* # include < stdio .h >
int main ( ) {
int N_ant , N_prox , N , N_atual
N_ant = N_atual =1;
for( i =1 ,i <= N , i ++) {
N_prox = N_ant + N_atual ;
N_ant = N_atual ;
N_atual = N_prox ;
printf ("Fim do laco !\n") ;
return
}*/
int main(){
	setlocale(LC_ALL, "Portuguese");
	printf("RESOLUÇÃO DA QUESTÃO 3\n");
	printf("Os erros de compilação são:\nno for, a iniciação e na condição não tem ;\ne no return não retorno para o valor e não tem ;\n");
	return 0;
}