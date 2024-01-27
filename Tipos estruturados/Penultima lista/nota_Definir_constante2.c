#include <stdio.h>

typedef enum boll{
true,
false
}BOLL;


int main(void){
BOLL resposta;
printf("\nVoce gosta de algoritmo? \n 0 - True\n 1 - False\n");
scanf("%d", &resposta);

if(resposta==true){
    printf("Boa escolha!\n");
}

if(resposta==false){
    printf("Que pena! \n");
}
    return 0;
}