#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    // Uso.
    Fila *Q = CriaFila(50);
    int elemento;

    InsereFila(Q, 10);

    ConsultaFila(Q, &elemento);
    

    RemoveFila(Q);

    DestruirFila(&Q); // Destrua a fila quando terminar de usá-la
}
