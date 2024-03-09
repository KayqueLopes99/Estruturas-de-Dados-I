## Tipos estruturados.
## Enum
. É um conjunto de valores inteiros representados por identificadores. 
. A sintaxe:
. Por padrão, a primeira constante é inicializada com zero.
enum nome_do_enum {
    constante1,
    constante2,
    ...
    constanteN
};


## Union
. Armazenar diferentes tipos de dados no mesmo espaço de memória. 
. A sintaxe:
union nome_da_union {
    tipo_de_dado1 variavel1;
    tipo_de_dado2 variavel2;
    ...
};


union dados{
    int meu_int;
    float meu_float;
}

union dados d;
// difereça para struct e union.
// UNION Armazena uma varíavel por vez, já em uma struct armazena tudo.

# Operador termario "?"

. Estrutura de controle condicional.
. Ele permite executar um bloco de código com base em uma condição, 

. Sintaxe: `condição ? valor se for verdadeiro : valor se for falso`.
- Exemplo:
```c
double salario = 1000;
double bonus = salario * (salario > 1000 ? 0.10 : 0.15);
```

**2. Função Getchar():**

A função `getchar()` é usada para ler um único caractere do terminal e devolver o código ASCII do mesmo⁶. A sintaxe é `int getchar();`⁷.

Aqui está um exemplo em C:

```c
#include <stdio.h>

int main(void) {
    char cLetra;
    cLetra = getchar();
    printf("Letra digitada %c\n", cLetra);
    printf("Na tabela ASCII %d\n", cLetra);
    return 0;
}
```

Neste exemplo, a função `getchar()` lê um caractere do terminal e o valor é atribuído à variável `cLetra`. Em seguida, o programa imprime o caractere digitado e seu valor na tabela ASCII⁶.

# Getchar();
