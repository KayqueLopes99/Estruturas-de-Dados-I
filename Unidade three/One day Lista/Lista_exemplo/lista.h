// Prótotipos

// Definição do tipo Lista
typedef struct lista Lista;

// Função que inicializa a lista, atribuindo NULL.
Lista * lista_cria(void);

// Função que insere os elementos inteiros na lista.
Lista * lista_insere_elemento(Lista * lista, int valor, int quantidade_escolhida);

// Função que imprime a lista.
void imprime(Lista * l);

// Função que verifica se a lista está vazia.
int verifica_elementos_vazio(Lista * l);

// Função que busca um elemento na lista.
Lista* Busca_elementos(Lista * l, int v);

// Função que retorna o número de nós da lista que possuem o campo info com valores maiores do que n.
int numero_de_no_da_lista_maiores_n(Lista * l, int n);

// Função liberar.
void libera_lista(Lista* l);

// Função remover.
Lista* lst_retira(Lista* l, int v);

// Função para o ultimo nó.
Lista* ultimo(Lista* l);

// Função para concatenar.
Lista* concatena(Lista* LISTA1, Lista* LISTA2);

// Função para retir geral.
Lista* retira_n(Lista* l, int n);