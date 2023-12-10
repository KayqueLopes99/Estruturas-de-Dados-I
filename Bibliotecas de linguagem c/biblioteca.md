## Bibliotecas de linguagem C 
## A biblioteca stdio.h
 - É uma biblioteca padrão da linguagem de programação C. Seu nome significa “cabeçalho padrão de entrada/saída”. 
 - Ela deve sempre está presente no código.
 - Seus comandos básicos são essenciais!

## A biblioteca stdlib.h 
- É uma biblioteca padrão da linguagem de programação C. 
- Ela possui funções envolvendo alocação de memória, controle de processos, conversões e outras.
- Alguns comandos:
atoi(): Converte uma string para um número do tipo int.
rand(): Gera um número inteiro pseudoaleatório.
malloc(), calloc(), realloc(): Funções para alocar memória.
free(): Libera memória alocada.
abort(): Força o término da execução do programa.
exit(): Termina a execução do programa.
system(): Executa um comando externo.

## A biblioteca locale.h
- Uso para acentuação no código.
- depois do int main (){
    setlocale(SET_ALL, "portuguese");
}

## A biblioteca string.h
-A biblioteca string.h é uma biblioteca padrão da linguagem de programação C que fornece funções, macros e definições para manipulação de cadeias de caracteres e regiões de memória.

strcpy(): Realiza a cópia do conteúdo de uma variável a outra2.
strcat(): Realiza a concatenação do conteúdo de uma variável a outra.
strlen(): Determina o tamanho de uma string.
strcmp(): Compara duas strings segundo sua ordem alfabética e retorna um inteiro.
strstr(): usada para encontrar a primeira ocorrência de uma substring dentro de uma string.
Onde:
str1 é a string na qual a busca será realizada.
str2 é a substring que estamos procurando dentro de str1.

## A biblioteca time.h
-A biblioteca time.h é uma biblioteca padrão da linguagem de programação C que fornece funções, macros e definições para manipulação de datas e horários.
time(): Retorna a data e hora do sistema e atribui esse valor à variável passada como parâmetro.

## A biblioteca math.h 
- fornece funções matemáticas em C, como cálculos trigonométricos, exponenciais, logarítmicos e outras operações matemáticas.

- sin(): Calcula o seno de um ângulo.
- cos(): Calcula o cosseno de um ângulo.
- tan(): Calcula a tangente de um ângulo.
- exp(): Calcula a exponencial (elevado à potência) de um número.
- log(): Calcula o logaritmo natural de um número.
- sqrt(): Calcula a raiz quadrada de um número.
- pow(): Calcula a potência de um número elevado a outro número.
- ceil(): Arredonda um número para cima para o inteiro mais próximo.
- floor(): Arredonda um número para baixo para o inteiro mais próximo.
- fabs(): Retorna o valor absoluto (módulo) de um número.
- fmod(): Calcula o resto da divisão entre dois números.
