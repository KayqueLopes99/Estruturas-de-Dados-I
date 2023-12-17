# Ponteiros 
 - O ponteiro, permite manipular valores e endereços de memória.
 - Transferência e alterações de dados também são executados pelos ponteiros.

 ## Endereço de uma varíavel 
 - Local onde é armazenada a memória.
 - São acessados pelos endereços através dos ponteiros.
 - O acesso a este contéudo, permite a manipuação.
  
 ## Operador de endereço &
 - É usado para acessar o endereço de memória de uma varíavel, permitindo assim a manipulação de dados associados a ela.
 - !Não se pode modificar o endereço de uma varíavel!

 ## Uso dos ponteiros !
 - Acesso e manipulação.
 - Passar informações e realizar operações.

 ## Declarando ponteiros
- São declarados usando o operador "*".
- Seguido da tipagem de dados, este pode ser usados para acessar e alterar os dados armazenados em memória.

## Implementação: Ponteiros em C
- Sintaxe da declaração de ponteiros:
.tipo_apontado*nome_da_variavel_ponteiro;
          int * point;
- Imprimindo o valor de um ponteiro
. printf("O ponteiro: %p \n", point);

## Acesso ao endereço de uma variável 
- int numero = 2; // DECLARAÇÕES.
- int * ponteiro;
- ponteiro = &numero // ACESSO AO ENDEREÇO DE NUMERO PELO PONTEIRO.

## Indireção de ponteiros com *
- Os ponteiros usam o operador * para fazer o acesso de dados armazenados em um endereço de memória.
- Assim com * acessamos o contéudo da varíavel.
## Exemplo:
            #include <stdio.h>
     int main(){
   
     float var = 3.14; // Declarou e estabeleceu um valor;

     float *point = &var; // O contéudo do ponteiro é igual ao endereço da varíavel;

    float pi = *point; // Declarou pi e associou ao contéudo do ponteiro;

    *point = 1.31; // Atribuiu um novo valor ao contéudo do ponteiro;
    
    printf("%f", var);
      }
## Operadores de Ponteiros 
- Acesso e manipulação, permitindo assim escrever e alterar os dados armazenados em memória.

## O ponteiro Nulo NULL
- É um ponteiro que não aponta para nenhum local ou objeto.
- indica ausência de valores validados.
- Exemplo:
-     # include <stdlib.h>
      char * ponteiro;
      ponteiro = NULL;

## Compatibilidade e converções entre ponteiros
- Versáteis.
- Entre diversos tipos de ponteiros há conversões também.
- Exemplo : 
-      float number;
       int * point;
      point = &number;
      point = (int*) &number; // forçar na associação.

## FORÇAMENTO 
- sintaxe:
- nome = (tipo_desejado*) &varíavel a ser forçada.
-// Isso permite que você acesse e manipule diretamente a memória onde "variavel" está armazenado.

## Aritmética 
- O calculo de deslocamento de ponteiros pode ser usado para acessar  dados específicos em estruturas complexas.
 
## Operações 
- Considerando que p é um ponteiro.
- Soma: p + 2.
- Subtração p - 3.
- Incremento ++p ou p++.
- Decremento de ponteiro --p ou p--.
- Subtração entre dois dois ponteiros do mesmo tipo p -p2.
- Em p - p2 ou p + p2, retornamos a um valor inteiro.

 ## EXEMPLO:
     int * pointer;
    pointer + 2;
        ...
    108[  ] P     
    104[  ] P+2
    100[  ] P
    99 [  ] P-1
        ...
// Representa o endereço da posição de memória que está dois objetos do tipo int adiante do endereço do objeto para o qual pointer aponta.

## Legal ou Ilegal !?

long *p1, *p2;
int j;
char *p3;
 
- p2 = p1 + 4; legal
- j  = p2 - p1; legal
- j  = p1 - p2; legal
- p1 = p2 - 2; legal
- p3 = p1 - 1; não é seguro !
- j  = p1 - p3; ilegal

## Usando funções com ponteiros
- Uma das maneiras é passar ponteiros como argumentos para uma função. Isso permite que a função acesse e modifique o valor de uma varíavel no própio escopo.

- EXEMPLOS DADO EM AULA:
-     #include <stdio.h>
      // Função "inc" que incrementa o número.
      int inc(int num) { 
      return (++num); 
         }
      // Função principal.
      int main(void) {
      // Declaração da variável com o valor 5.
       int numero = 5;
      // Chamada da função "inc" para incrementar.
      numero = inc(numero);

      // Impressão do valor.
      printf("%d", numero);

      // Retorno 0 em caso com sucesso.
      return 0;
       }*/
## Antes de mais nada, o que é uma função?
- Resolver problemas complexos através de combinação de soluções menores.
- sintaxe <tipo> <nome_da_função>(<parâmetros>){
    <bloco_de_comandos>
    return <informações>
}
-  Função com vetor
  -       void nomeDaFuncao(tipo vetor[], int tamanho) {
         // corpo da função
}

-  Função com matriz
-      
         void nome_da_funcao(tipo nome_da_matriz[num_linhas][num_colunas]){
        // corpo da função
          }
  
## Usando Funções com Ponteiros 
- Usar ponteiros como retorno de função. isso permite que uma função retorne um endereço de memória para uma variável.
-Exemplo:
-      int *cria_variavel(){
      int variavel = 5;

      return &variavel;
         }
       int main() {
       int *ponteiro = cria_variavel();
    
      printf("Valor da varíavel: %d", *ponteiro);
       return 0;
       }

## Os ponteiros de função 
- Os ponteiros de função são usados para apontar para uma função específica, permitindo que a função passa a ser chamada diretamente. 
- Função passada como parâmentro para outras funções.
- Declaração 
<tipo>,<nome><parâmetros (recebidos)>
                             |_ Retornar.

-     int (*ponteiro)(int, int);
- Isso declara um ponteiro chamado "ponteiro" que é um ponteiro para uma função que tem um tipo de retorno inteiro e dois parâmetros inteiros.

## Explicações entendidas:
-      #include <stdio.h>
       int main(void) {
      int x, y; //variáveis.
       y = 2; //atribuição de 2 a y.
       int *p1, *p2; // Ponteiros.
      p1 = &y; //Endereço de  y atribuido a p1.
       x = 1; // atribuição de 1.
      p2 = p1; // contéudo de p1 = p2.
      (*p1)++; // incremento
       printf("%d %d", x, y);

      return 0;
       }



   -  //(*p1)++ ou *(p++): o valor é incremetado  
   - o valor apontado por p1 é incrementado após a operação de desreferenciamento:
   -     exemplo:
     -     #include <stdio.h>
-      int main() {
       int n = 4;
       int *p1;
       int i = 3;
       int r;

       p1 = &n;
    
       printf("Resultado: %d\n",  r = i + (*p1)++);
           return 0;
           }
   // o resultado não será 8 e sim 7.

  - *p1++:
  -  Neste caso, significa que o valor apontado por p1 é obtido primeiro, ou seja, ele faz somente a soma normal
         //sem atribuições por enquanto.
         //e em seguida, o ponteiro p1 é incrementado.
  -     #include <stdio.h>

        int main() {
        int n = 4;
        int *p1;
        int i = 3;
        int r;

        p1 = &n;
    
         printf("Resultado: %d\n",  r = i + (*p1++));
        return 0;
         }
    
         //++p1 atribui a incremento na operação e no ponteiro.
        #include <stdio.h>
        int main() {
        int n = 4;
        int *p1;
        int i = 3;
        int r;

        p1 = &n;
    
        printf("Resultado: %d\n",  r = i + ++*p1);
        return 0;
        }

         logo o resultado será 8

## Conclusão:

- Concluímos que os ponteiros permitem a tranferência de dados.
- "*" = contéudo.
- & = endereço.
- Alterar e acessar dados.


## observações
- **p = Indica que p é um ponteiro para um ponteiro. Isso é frequentemente 
usado para representar matrizes em C, onde cada elemento do primeiro ponteiro 
aponta para um array do seu tipo.













































