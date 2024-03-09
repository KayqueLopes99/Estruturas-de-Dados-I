## COM WT

#include <stdio.h>
#include <stdlib.h>

int main(void){

FILE* segundo_arquivo = fopen("twoquestion.txt", "wt");

if(segundo_arquivo == NULL){
    printf("Errouuuu");
    exit(1);
}

else{
    printf("Sucesso");
}

if(!close(segundo_arquivo)){
printf("Fechado com sucesso !!!\n");
}

return 0;

}