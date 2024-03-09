#include <stdio.h>
// Qual a complexidade de temppo?
int funcao_aula(int max1, int max2){
int cont1, cont2; // 1 vez.
for(cont1=0; cont1<max1; cont1++){ // c2 n vez.
for(cont2=0; cont2<max2; cont2++){ // c3 nxn = (n^2) vez.
    printf("Exemplo da aula:"); // c4 (n^2) vez.

}
}
return 0; // /c5 1 vez.
}

//T(funcao_aula) = c1 + n.c2 + n.nc3 + c5
//T(funcao_aula) = (c3 + c4)n^2 + nc2 + (c1 + c5) :. a = (c3 + c4) | c = (c1+c5) | b =c2
//T(funcao_aula) = an^2 + bn + c. 
// Simplificação: contantes e  menores graus e multiplicações, deixando só o de maior impacto.
//T(funcao_aula) = ( n^2 ). 
// Notação Big-o: 
// T(funcao_sala) = 0(n^2).
// Pior caso = Maior tempo.
// Caso médio = Em todas as entradas estão no estatíco.
// Melhor caso = a melhor em tudo.

/*
Questão 2 - ainda copiar.

T(MAX) = a(n-1) + b = an -a + b
Simplificação da expressão do tempo:
T(MAX) = an -a+b
T(MAX) = an
T(MAX) = n
Notação Big-O:
T(MAX) = 0(n)

*/

void insertSort(int arr[], int n){
int i, key, j;
for(i = 1; i < n; i++){
key = arr[i];
j = i - 1;
while(j >= 0 && arr[j] > key){
arr[j + 1] = arr[j];
j = j - 1;
}

arr[j + 1] = key;
}
}
/*
Operação. 
c1 = 1 vez.
c2 = (n - 1)
c3 = (n - 1)
While -> para organizar. 
c4 = n1.n2
c5 = n1.n2
c6 = (n1 - 1)

O pior caso:
c1 + n(c2 + c3 + c6) + n^2 (c4 + c5)
a + bn + n^2 
0(n^2)

Melhor caso:
c1 + n(c2 + c3 + c6)
a + bn
0(n)
*/