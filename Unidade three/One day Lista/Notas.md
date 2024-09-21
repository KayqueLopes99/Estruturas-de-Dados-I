# Listas encadeadas

## Introdução:
- O vetor é a forma mais primitiva de representar diversos elementos agrupados.

```` C
#define MAX 1000
int vet[MAX];

````
. [ ][ ][ ][ ][ ][ ]

## Listas encadeadas 
- Espaço de memória proporcional ao número de elementos da lista.
- Não há garantia de armazenamento contíguo.
- É importante guardar o encadeamento da lista.


## Lista Encadeada:
    - Um nó da lista contém:
        - Informação armazenada.
        - Ponteiro para o próximo elemento.
    - A lista é representada por um ponteiro para o primeiro nó. O ponteiro do último elemento é NULL.
    - O diagrama mostra três nós rotulados como "Info1", "Info2" e "Info3", conectados por setas que representam os ponteiros.
    - Cada nó consiste em um retângulo com informações e uma seta apontando para o próximo nó, indicando que é uma lista encadeada simples.

````c
L --> [INFO1[]] --> [INFO2[]] -->[INFO3[]] -->

````

## Conceito: 
- Uma lista encadeada é uma estrutura de dados que consiste em uma sequência de nós, onde cada nó contém um valor (ou um conjunto de valores) e um ponteiro para o próximo nó na sequência. 


## Passos do código: 
### Struct lista 
- Ela contém dois campos:

**int informacao**: 
- Tem o valor inteiro que representa a informação  que o nó da lista está armazenando.

**Lista * prox_elemento**: 
- Este é um ponteiro para o próximo nó na lista.

- Ele é usado para "encadear" os nós juntos, formando a lista encadeada.

- Se este campo é `NULL`, isso indica que este nó é o último nó da lista.

- Para percorrer a lista, você começa no primeiro nó e segue os ponteiros 
`prox_elemento` de um nó para o próximo.

```c
// Tipo estruturado com dados.
 struct lista
{
    int informacao;
    Lista * prox_elemento;

};
```

### Função cria_lista:
- `Lista * lista_cria(void)`: 
- Cria uma lista encadeada vazia.

- Retorna `NULL`, que é usado para representar uma lista vazia em listas encadeadas.

```c
Lista * lista_cria(void){
    return NULL;
}
```

### Função verifica_elementos_vazio:
- `int verifica_elementos_vazio(Lista * l)`: 

- Verifica se uma lista encadeada está vazia. 

- Ela faz isso verificando se o ponteiro para a lista é `NULL`. Se for `NULL`, a função retorna 1 (verdadeiro) e imprime "Lista Vazia". 

- Se não for `NULL`, a função retorna 0 (falso) e imprime "Lista cheia!".

```c
// Função que verifica se uma lista está vazia.
int verifica_elementos_vazio(Lista * l){
if(l == NULL){
printf("Lista Vazia");
return 1;
}
else{
printf("Lista cheia!");
return 0;
}
```

### Função lista_insere_elemento
- `Lista * lista_insere_elemento(Lista * lista, int valor, int quantidade_escolhida)`:

 Esta função insere um novo elemento no início da lista encadeada. Ela faz isso da seguinte maneira:
   - Aloca memória para um novo nó usando a função `malloc`.

   - Verifica se a alocação foi bem-sucedida. 

   - Armazena o valor fornecido no campo `informacao` do novo nó.

   - Conecta o novo nó à lista existente, fazendo o campo `prox_elemento` do novo nó apontar para o primeiro nó da lista original.

   - Finalmente, ela retorna o novo nó, que agora é o primeiro nó da lista atualizada.

````c
// Inserção no início: retorna a lista atualizada.
Lista * lista_insere_elemento(Lista * lista, int valor, int quantidade_escolhida){
    Lista * novo_no = (Lista*) malloc(sizeof(Lista));// Alocação. 
    if(novo_no==NULL){
        exit(1);
    }
    // Adiciona o valor no campo informação.
novo_no->informacao = valor;
   // Conecta o novo nó a lista.
novo_no->prox_elemento = lista;
return novo_no;
}
````

### Função de percorer para imprimir:
- `void imprime(Lista * l)`:
- Esta função percorre a lista e imprime cada elemento.

- Cria um ponteiro para percorrer a lista.

- Loop passa por cada elemento na lista até chegar ao final (`NULL`).

- Começa fazendo contador apontar para o primeiro nó da lista (contador = l).

- Em (contador != NULL) verifica se o contador chegou ao final da lista. 

- Se contador for NULL, isso significa que chegamos ao final da lista e o loop termina. 

- A cada iteração do loop, contador é movido para o próximo nó da lista em (contador = contador->prox_elemento).

- Imprime a informação do nó atual.

```` c
// Imprissão da lista com loop para percorer.
void imprime(Lista * l){
    // criou o ponteiro para percorrer a lista.
    Lista * contador;
    for(contador = l; contador != NULL; contador = contador->prox_elemento){

        printf("%d\t", contador->informacao);
    }
} 
````

### Função Busca_elementos:
- Esta função procura um elemento específico na lista.


    - Esta linha cria um ponteiro para percorrer a lista.

    -  Este loop passa por cada elemento na lista até chegar ao final (`NULL`).
    
    - Segue a mesma lógica da anterior.

    - Se a informação do nó atual for igual ao valor procurado, a função retorna o nó.

    - Se a função não encontrar o elemento, ela retorna `NULL`.

````c
// Faça uma função que busca um elemento na lista.
Lista* Busca_elementos(Lista * l, int v){
    Lista* p;

    for(p = l; p != NULL; p = p->prox_elemento){
      //  verifica se o ponteiro está apontando para v procurado
        if(p->informacao == v)
            return p;
    }

    return NULL; // Não achouu!!
}
````

### Função numero_de_no_da_lista_maiores_n
- Esta função conta o número de nós na lista que têm um valor maior que `n`.

- Inicializa um contador.

- Este loop passa por cada elemento na lista até chegar ao final (`NULL`).

- Segue a mesma lógica da insere.

- Se a informação do nó atual for maior que `n`, o contador é incrementado.

- A função retorna a contagem.


````c
int numero_de_no_da_lista_maiores_n(Lista * l, int n){
    int contador_do_conteudo = 0;
    Lista* p;
// Percorre a lista. Para cada nó na lista.
    for(p = l; p!= NULL; p = p->prox_elemento){
        if(p->informacao > n)
            // incrementa o contador.
            contador_do_conteudo++;
    }
    return contador_do_conteudo;
}
````

### Função de Liberar:
- Esta função libera a memória alocada para a lista.

- Esta linha cria um ponteiro para o primeiro nó da lista.

- Este loop passa por cada elemento na lista até chegar ao final (`NULL`).

- Esta linha salva o ponteiro para o próximo nó antes de liberar o nó atual.

- Esta linha libera a memória do nó atual.

- Esta linha move o ponteiro para o próximo nó. 

````c
void libera_lista(Lista* l){
Lista * lista_atual = l; // aponta para o primeiro. 
// Enquanto a lista não estiver vazia.
while (lista_atual != NULL){
    Lista* proximo_apontado = lista_atual->prox_elemento;
    free(lista_atual);
    lista_atual = proximo_apontado;
} 
````

## Função lst_retira:
Lista* (Lista* l, int v)
- Esta função é usada para remover um elemento de uma lista encadeada.

- Inicializando dois ponteiros, `ant` e `p` para o início da lista.

- ant é usado para rastrear o nó anterior na lista encadeada.

- p é usado para percorrer a lista.

- Loop, procurando o elemento que corresponde ao valor `v` que queremos remover.

- Se `p` se torna `NULL` (o que significa que chegamos ao final da lista) ou encontramos o elemento desejado (`p->informacao == v`), logo saímos do loop.

- Se `p` é `NULL` após o loop, elemento não foi encontrado na lista. 

- Logo retorna a lista original sem fazer nenhuma modificação.

- Se o elemento foi encontrado, então ele é removido.
-(inicio) Se `ant` é `NULL`, isso significa que o elemento a ser removido está no início da lista. Nesse caso, movemos o ponteiro `l` (que aponta para o início da lista) para o próximo elemento.

-(meio) Se `ant` não é `NULL`, isso significa que o elemento a ser removido está em algum lugar no meio da lista. Nesse caso, fazemos o elemento anterior (`ant`) apontar para o elemento depois de `p` (`p->prox_elemento`).

- Liberamos a memória ocupada pelo elemento que acabamos de remover.

- Retorna a lista modificada ou não caso não ache.


````c
/* função retira: retira elemento da lista */
Lista* lst_retira(Lista* l, int v) {
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista */

    /* procura elemento na lista, guardando anterior */
    while(p != NULL && p->informacao != v) {
        ant = p;
        p = p->prox_elemento;
    }

    /* verifica se achou elemento */
    if (p == NULL) {
        return l; /* não achou: retorna lista original */
    }

    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do início */
        l = p->prox_elemento;
    } else {
        /* retira elemento do meio da lista */
        ant->prox_elemento = p->prox_elemento;
    }
    free(p);
    return l;
}

````