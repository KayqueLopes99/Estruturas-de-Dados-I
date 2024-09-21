/*
1) Considere listas encadeadas de valores inteiros e implemente uma função para
retornar o número de nós da lista que possuem o campo info com valores
maiores do que n. Essa função deve obedecer ao protótipo: int maiores(Lista* l,
int n); (FEITA).

2) Implemente uma função que tenha como valor de retorno o ponteiro para o
último nó de uma lista encadeada. Essa função deve obedecer ao protótipo:
Lista* ultimo(Lista* l);(FEITA).

3) Implemente uma função que receba duas listas encadeadas de valores reais e
retorne a lista resultante da concatenação das duas listas recebidas como
parâmetros, isto é, após a concatenação, o último elemento da primeira lista
deve apontar para o primeiro elemento da segunda lista, conforme ilustrado a
seguir:
Essa função deve obedecer ao protótipo: Lista* contatena(Lista* l1, Lista* l2);(FEITA).

4) Considere listas de valores inteiros e implemente uma função que receba como
parâmetros uma lista encadeada e um valor inteiro n, retire da lista todas as
ocorrências de n e retorne a lista resultante. Essa função deve obedecer ao
protótipo: Lista* retira_n(Lista* l, int n); (Feita).
*/
#include <stdio.h>
#include "lista.h"
#include <stdlib.h>

int main(void) {
    Lista* lista_encadeada = lista_cria();
      Lista* lista_encadeada2 = lista_cria();
    int quantidade_escolhida, valor, opcao, i;

    do {
        printf("\nMenu:\n");
        printf("1. Inserir elementos na lista\n");
        printf("2. Imprimir lista\n");
        printf("3. Buscar elemento na lista\n");
        printf("4. Encontrar elemento maiores\n");
        printf("5. Remover elemento\n");
        printf("6. Encontrar Ultimo elemento\n");
        printf("7. Concatenar duas listas\n"); 
        printf("8. Inserir elementos na segunda lista\n");
        printf("9. Remover todos os elementos correspondentes\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Insira a quantidade de elementos da lista: ");
                scanf("%d", &quantidade_escolhida);
                for (i = 0; i < quantidade_escolhida; i++) {
                    printf("Insira o %d algarismo: ", i + 1);
                    scanf("%d", &valor);
                    lista_encadeada = lista_insere_elemento(lista_encadeada, valor, quantidade_escolhida);
                }
                break;
            case 2:
                // Chamar a função.
                imprime(lista_encadeada);
                break;
            case 3:
                printf("Insira o numero que deseja buscar: ");
                scanf("%d", &valor);
                Lista* resultado = Busca_elementos(lista_encadeada, valor);
                if (resultado != NULL) {
                    printf("Numero encontrado na lista.\n");
                } else {
                    printf("Numero no encontrado na lista.\n");
                }
                break;
                case 4:
   printf("Digite um numero: ");
    scanf("%d", &valor);
    int resultado_maior;
    resultado_maior = numero_de_no_da_lista_maiores_n(lista_encadeada, valor);
    printf("Numero de nos com valores maiores do que %d: %d\n", valor, resultado_maior);
                break;
                 case 5:
                printf("Insira o valor que deseja retirar: ");
                scanf("%d", &valor);
                lista_encadeada = lst_retira(lista_encadeada, valor);
                printf("Valor retirado com sucesso.\n");
                break;
                case 6:
                ultimo(lista_encadeada);
                break;
            case 7:
                lista_encadeada = concatena(lista_encadeada, lista_encadeada2);
                printf("Listas concatenadas com sucesso.\n");
                break;
                case 8:
                printf("Insira a quantidade de elementos da segunda lista: ");
                scanf("%d", &quantidade_escolhida);
                for (i = 0; i < quantidade_escolhida; i++) {
                    printf("Insira o %d algarismo: ", i + 1);
                    scanf("%d", &valor);
                    lista_encadeada2 = lista_insere_elemento(lista_encadeada2, valor, quantidade_escolhida);
                }
                break;
               case 9:
    if (lista_encadeada == NULL) {
        printf("Nada a retirar\n");
    } else {
        printf("Insira o valor que deseja retirar geral: ");
        scanf("%d", &valor);
        lista_encadeada = retira_n(lista_encadeada, valor);
        printf("Valor retirado\n");
    }
    break;

            case 0:
                printf("Saindo.\n");
                break;
            default:
                printf("Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libere.
libera_lista(lista_encadeada);
    return 0;
}
