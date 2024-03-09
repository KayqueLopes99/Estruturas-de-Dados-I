#include <stdio.h>
#define TRUE 0
#define FALSE 1

int main(void){
int resposta;
printf("\nVoce gosta de algoritmo? \n 0- True\n 1-False\n");
scanf("%d", &resposta);
if(resposta==TRUE){
    printf("Boa escolha!\n");
}
if(resposta==FALSE){
    printf("Que pena! \n");
}
    return 0;
}