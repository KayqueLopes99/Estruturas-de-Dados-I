#include <stdio.h>
#include "aluno.c" //se eu quiser compilar direto posso só colocar o ponto c

int main(void){
    Aluno * aluno;
    aluno = recebe_dados();
    exibe_aluno(aluno); 
    limpar(aluno);
    return 0;
}
