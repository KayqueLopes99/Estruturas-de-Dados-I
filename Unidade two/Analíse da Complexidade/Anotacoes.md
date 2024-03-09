## Analíse de um algoritmo:
- Sequência finita de instruções bem definidas e não ambíguas, cada uma das quais devendo ser executadas
em um intervalo de tempo finito e com uma quantidade de esforço finita.

## Complexidade do espaço: 
- O espaço requerido por um algoritmo depende de dois componentes:
a. Uma parte fixa que é independente das características de
entradas/saídas.
b. Uma parte variável que é dependente da instância do problema
sendo resolvido.
- Assim, o espaço requerido S de qualquer algoritmo P, pode ser escrito
como: S(P) = c + Sp

- Espaço independentente temos Sp = 0;
- No exemplo abaixo, vemos abc e o resultado tem espaço independente das caracteres da instância.

````c
float abc(int a, int b, int c) {
 return a+b+b*c+(a+b-c)/(a+b)+4.0
}

````

## Em síntese:
- A complexidade de espaço de um algoritmo é determinada pela quantidade total de memória que o algoritmo precisa para executar. Isso inclui a memória necessária para armazenar variáveis de diferentes tipos (como int, float, etc.), estruturas de dados (como arrays, listas, etc.) e a pilha de execução.

- Temos 4 bytes para uma varíavel, logo O(n) = 4(n). Mas a complexidade de espaço seria O(n), porque o espaço necessário cresce linearmente com n.

- Lembrando que:
- int: 4 bytes - 32 bits.
- char: 1 byte - 8 bits.
- float: 4 bytes - 32 bits.
- double: 8 bytes - 64 bits.

# Complexidade do tempo:
- O tempo de execução numa determinada entrada, é o número de operações primitivas executadas.

- Operações primitivas: atribuições, comparações, somas, etc.

- Cada linha do pseudocódigo requer tempo constante para ser executado (independente do tamanho do input).

- Linhas diferentes podem requerer tempos diferentes.

- O tempo total é a soma dos tempos de cada linha do algoritmo.

````c
int Max(int arr[], int n){
    int i;
    int max = arr[0];
    // A complexidade de tempo deste loop é O(n)
    for (i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

````


# Complexidade de Tempo dos Loops e Declarações Condicionais

## 1. Loop for

A complexidade de tempo de um loop for é determinada pelo número de vezes que o loop é executado. 

- Se o loop for é executado n vezes, a complexidade de tempo é O(n). 
- Se você tem um loop for aninhado dentro de outro loop for (um loop for duplo), e cada loop é executado n vezes, a complexidade de tempo é O(n^2). 

## 2. Loop while

A complexidade de tempo de um loop while é novamente determinada pelo número de vezes que o loop é executado. 

- Se o loop while é executado n vezes, a complexidade de tempo é O(n). 
- Como com o loop for, loops while aninhados aumentarão a complexidade de tempo proporcionalmente.

## 3. Declarações if e else

As declarações if e else em si têm uma complexidade de tempo constante, O(1), porque elas apenas verificam uma condição e depois seguem um caminho ou outro. No entanto, o código dentro dos blocos if e else pode ter sua própria complexidade de tempo. 

- Por exemplo, se você tem um loop for dentro de um if, a complexidade de tempo seria O(n) se a condição if for verdadeira, e O(1) se for falsa.

## Exemplo:

`````c

void insertionSort(int arr[], int n){
    int i, key, j;
    // Complexidade de tempo: O(n)
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Complexidade de tempo: O(n) no pior caso
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


`````
- Temos for e while n vezes: logo:
- Pior caso:  O(n^2) 
- Caso médio:  O(n^2) 
- Melhor caso: (O(n) 

# Complexidade de Tempo - Tipos de Análise

## Pior caso:
- Maior tempo de execução do algoritmo para qualquer entrada do tamanho n.
- É o tipo mais utilizado. Todos gostam da garantia.

## Caso médio:
- Tempo esperado do um algoritmo sobre todas as entradas do tamanho n.
- Necessidade usar distribuição estatística.

## Melhor caso:
- Raramente é feita

# Notação Big O

- É uma notação matemática usada para classificar algoritmos de acordo com como o tempo de execução.

- A notação Big O descreve o limite superior do crescimento de uma função. Por exemplo, se temos uma função `f(n)` que cresce proporcionalmente ao quadrado do tamanho da entrada `n`, dizemos que `f(n)` é `O(n²)`.

- Como um Conjunto: A notação Big O pode ser vista como um conjunto que contém todas as funções que crescem no mesmo ritmo ou mais lentamente que `g(n)`. Quando dizemos `f(n) = O(g(n))`, estamos afirmando que `f(n)` pertence a esse conjunto.

