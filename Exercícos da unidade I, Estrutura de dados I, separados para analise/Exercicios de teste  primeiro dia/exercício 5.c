#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	printf("RESOLUÇÃO DA QUESTÃO 5");
	/* # include < stdio .h >
int main ( ) {
int i ;
for ( i =1 ; i <= 100 ; i *=100) {
if ( i ==30 ) {
break ;
}
else {
printf ("%2d\n" ,2* i ) ;
}
}
printf ("Fim do laco !\n") ;
return 0;
}*/
	printf("A variável i é equivalente a 1, então 1 * 100 = 100, isso no loop do for\n");
	printf("continuando como i = 1 é menor e não é igual a 30 ele continua\n");
	printf("levando o resultado de i ser multiplicado por 2.\n");
	return 0;
}