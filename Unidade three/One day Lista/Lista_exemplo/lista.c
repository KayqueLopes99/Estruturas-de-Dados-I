#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

// Tipo estruturado com dados.
 struct lista
{
    int informacao;
    Lista * prox_elemento;

};

// Lista *vet = NULL;
// É a mesma coisa.
// Criação da lista.
Lista * lista_cria(void){
    return NULL;

}

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

// Imprissão da lista com loop para percorer.
void imprime(Lista * l){
    // criou o ponteiro para percorrer a lista.
    Lista * contador;
    for(contador = l; contador != NULL; contador = contador->prox_elemento){

        printf("%d\t", contador->informacao);
    }
}

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

}
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

void libera_lista(Lista* l){
Lista * lista_atual = l; // aponta para o primeiro. 
// Enquanto a lista não estiver vazia.
while (lista_atual != NULL){
    Lista* proximo_apontado = lista_atual->prox_elemento;
    free(lista_atual);
    lista_atual = proximo_apontado;
} 


}

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


Lista* ultimo(Lista* l){
 /*Verifica se está vazio.*/
if(l == NULL){
printf("Vazio\n");
return NULL;
}
 /* Percore para o ultimo nó.*/
while(l-> prox_elemento != NULL){
l = l->prox_elemento;
}
printf("O Ultimo no: %d\n", l->informacao);
return l;
}


/* Função para concatenar duas listas encadeadas*/
Lista* concatena(Lista* LISTA1, Lista* LISTA2) {
    if (LISTA1 == NULL) {
        printf("Lista 1 vazia!\n Logo a Lista está sendo verificada:\n");
        return LISTA2;
    }
    /* Ponteiro auxiliar para percorreer a lista*/
    Lista* auxilio = LISTA1;
    /* Percorer até o ultimo nó e concatenar com o primeiro da lista 2.*/
    while (auxilio->prox_elemento != NULL) {
        auxilio = auxilio->prox_elemento;
    }
    /* Quando percorer vai ligar e retornar.*/
    auxilio->prox_elemento = LISTA2;
    return LISTA1;
}

Lista* retira_n(Lista* l, int n) {
    Lista* ant = NULL; /* ponteiro para elemento anterior. */
    Lista* p_auxiliar = l; /* ponteiro para percorrer a lista. */
    Lista* Liberador; /* Pomteiro auxiliar para liberar. */

    /* procura todos referentes a n. */
    while(p_auxiliar != NULL) {
        /* Em casos de verificação para retirada. */
        if(p_auxiliar->informacao == n) {
            if (ant == NULL) {
                /* retira elemento do início. */
                l = p_auxiliar->prox_elemento;
            } else {
                /* retira elemento do meio da lista. */
                ant->prox_elemento = p_auxiliar->prox_elemento;
            }
            /* Atualização. */
            Liberador = p_auxiliar;
            p_auxiliar = p_auxiliar->prox_elemento;
            free(Liberador);
        } else {
            /* Atualização. */
            ant = p_auxiliar;
            p_auxiliar = p_auxiliar->prox_elemento;
        }
    }
    return l;
}
