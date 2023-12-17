# Alocação dinâmica: Vetores e Matrizes 

## Antes de mais nada apresento-lhes o que é Matriz:
- Explicação: É uma estrutura de dados que armazena elementos em linhas e colunas.

- Sintaxe:
-     tipo nome_matriz[linhas][colunas];
Acesso aos elementos:
- Exemplo:
-     int elemento = matriz[1][2]; // Acessando o elemento da  linha e da coluna

Inicialização: // Caso você queira já definir os valores da matriz.
- Sintaxe:
-      tipo nome_matriz[linhas][colunas] = {{valor1, valor2, ... ,valor n},
-      {valor3, valor4, ... ,valor n}};
- Exemplo:
-      int matriz[2][2] = {{1, 2}, {3, 4}}; 

- Loops para percorrer as linhas e colunas da matriz e realizar operações nos elementos.
- Exemplo:
-       for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
        printf("%d ", matriz[i][j]);
        }
        printf("\n");
         }

##  Antes de mais nada apresento-lhes o que é um Vetor:

- Explicação: Um vetor é uma estrutura de dados que armazena elementos.
- Sintaxe: tipo nome_vetor[tamanho];
- Exemplo: int vetor[5];

Acesso aos elementos:
- Sintaxe: valor = nome_vetor[<indice> OU <posição>];
- Exemplo: int elemento = vetor[9];

Inicialização:
- Sintaxe:
-     tipo nome_vetor[tamanho] = {valor1, valor2, ...};
- Exemplo: int vetor[9] = {7, 8, 9}; 
- loops para percorrer os elementos do vetor e realizar operações caso precise.
- Exemplo:
-      for (int i = 0; i < tamanho; i++) {
      printf("%d ", vetor[i]);
      }

## Alocação estática 

- A alocação estática de vetor e matriz é feita em tempo de compilação, onde o tamanho é fixo e definido.
-  Não sendo possível mudar ou alterar nada.
- Exemplo:
   int vetor[5] = {1, 2, 3, 4, 5};

## Alocação Dinâmica

- A alocação dinâmica de memória é um processo de alocar espaço de memória durante a execução de um programa.
- Assim, podemos alocar e liberar espaço de memória 
- Útil em situações em que o tamanho da estrutura é desconhecido na compilação.

### ALERTAAAAAAAAAAAAAAAAAAAA!!!!!!!!!!

- É importante notar que a alocação dinâmica de memória também exige
liberação manual de memória, usando a função free(). Se essa liberação. 

- USE O FREE(); SEM FALTA!!!

### Estruturas e comandos
## Malloc:
- Descrição: A função malloc() em C, que significa alocação de memória, é utilizada
para reservar um espaço de memória com um tamanho e armazenar estes dados.

- Este comando é da biblioteca stdlib.h e recebe como descrição números que representam os 
bytes (size_t), o qual serão alocados.

- Sintaxe: 
-      <tipo> *varíavel = (<tipo> *) malloc(tamanho * sizeof(int));
      if (variável == NULL){
		print("Não foi  possível: \n");
		exit(1);
	  }
	  else {
		printf("Alocação realizada com sucesso\n");
	   }
       free(variável);
Exemplo:
-     int *ponteiro = (int *) malloc(5 * sizeof(int));
      free(ponteiro);
  
- Explicações: malloc é armazenar !
- int *variavel: Declaração de uma variável, o qual o tipo de dado é um ponteiro para tipo(tipo *). 
- Isso significa que a varíavel pode armazenar o endereço de um tipo.

- O malloc(tamanho * sizeof(int)): A função malloc tem tamanho * sizeof(int) é a quantidade de bytes
para armazenar.
- O sizeof(int) retorna o tamanho em bytes de um tipo.

. Multiplicando obtemos o tamanho total em bytes necessário para armazenar o vetor.

. O malloc retorna um ponteiro para a memória alocada, com (int *).

## Calloc:
- Descrição: A função calloc em C é usada para alocar uma quantidade de memória para um 
número de elementos.
- Reserva um espaço de memória e inicializa o a varíavel com zeros.
- Garante a aproximadamente 0% de lixo nas posições.

- A função calloc(), Ela faz parte da biblioteca stdlib.h e recebe como argumentos em (sizeof),
que representam a quantidade(Elementos) e o tamanho(Bytes).
- Sintaxe:
tipo *variável = (tipo *) calloc(tamanho,sizeof(tipo));
- A função retorna um ponteiro contendo o endereço do bloco de memória alocado. Assim, ela é flexível.

## Realloc:
- A função realloc() é uma função em C que é usada para redimensionar uma área
de memória já alocada.

-Ela tem a seguinte sintaxe:
void *realloc(void *ptr, size_t size);

- A função realloc() é útil quando você precisa alocar mais memória para um vetor
ou matriz dinâmica, mas não quer perder os dados já armazenados nele. Ela
também pode ser usada para liberar espaço desnecessário, se o novo tamanho
for menor do que o antigo.

- size_t size: O novo tamanho em bytes que você deseja para o bloco de memória.

## free(); 
- Liberar os dados na memória.
- Sintaxe : free(ponteiro);

## exit();
- Código de saída do programa.
- Sintaxe : exit(código de saída);

## sizeof;
- Usado para obter o tamanho.
- Sintaxe : sizeof(tipo);

## Declarando vetores Dinamicamente
-      int *vetor = (int *) malloc(tamanho * sizeof(int));
- OU
-      int *vetor = (int *) calloc(tamanho, sizeof(int));
  
- Ao usar as funções malloc e calloc, é importante verificar se a alocação foi
bem-sucedida, pois elas retornam o ponteiro NULL em caso de falha.

### EXEMPLO ESTÁ ANEXADO EM ARQUIVO (exemplos de alocação)

## Exemplo:

-     #include <stdio.h>
      #include <stdlib.h>
      int main() {
      int tamanho = 5, novo_tamanho;
      int *vetor = (int *) malloc(tamanho * sizeof(int));
      printf("\nEntre com o novo tamanho do vetor: ");
      scanf("%d", &novo_tamanho);
      vetor = (int *) realloc(vetor, novo_tamanho * sizeof(int));
      if (vetor == NULL) {
      printf("Erro ao alocar memória");
      exit(1);
      }
      else {
		printf("Alocação realizada com sucesso\n");
	}

      free(vetor);
       return 0;}

 ## Declarando matrizes
 - Ela é utilizada para representar dados
relacionados a tabelas, imagens, entre outros.
-         0  1   2 colunas.
      0- |  |  |  |
      1- |  |  |  |
      2- |  |  |  |
          linhas.

## Exemplo: Alocando Matrizes Dinamicamente
-     #include <stdio.h>
      #include <stdlib.h>
      int main() {
      int linhas=3, colunas=3, i, j;
       // Alocando vetor de ponteiros
       int **matriz = (int **) malloc(linhas * sizeof(int *));
      // Alocando cada linha da matriz
       for (i = 0; i < linhas; i++) {
      matriz[i] = (int *) malloc(colunas * sizeof(int));
        }
      // Liberando a memória alocada
      for (i = 0; i < linhas; i++) {
       free(matriz[i]);
       }
       free(matriz);
       return 0;
         }


### QUESTÃO DE PROVA !?
-      *(vetor+1); 
      (*vetor+1); 
       //explicações:
       A diferença fundamental reside em que *(vetor+1) acessa o valor na segunda posição do array,
       enquanto (*vetor+1) adiciona 1 ao valor da primeira posição do array. 




