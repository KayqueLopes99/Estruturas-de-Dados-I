/*
Questão 2) Escreva um programa em C que preencha um vetor de 10 inteiros com informações
vindas de um arquivo e escreva em outro arquivo o menor elemento, o maior elemento, bem
como a média dos elementos do vetor, como ilustrado a seguir. 

*/
#include <stdio.h>
#include <stdlib.h>

int main(void){

    // Abre o arquivo de entrada para leitura
    FILE* arquivo_entrada = fopen("twoquestionentrada.txt", "r");
    float soma_media = 0;
    float numero_maior, numero_menor;
    int contador = 0;
    float resultado = 0;
    float numeros;
    if(arquivo_entrada == NULL){
        printf("Erro ao abrir");
        exit(1);
    }
    else{
        printf("Arquivo aberto com sucesso\n");
    }

    // Le o primeiro numero
    if(fscanf(arquivo_entrada, "%f", &numeros) != EOF){
        numero_menor = numero_maior = numeros;
        soma_media += numeros;
        contador++;
    }

    // Le os numeros restantes
    while(fscanf(arquivo_entrada, "%f", &numeros) != EOF){
        if(numeros > numero_maior) numero_maior = numeros; // Atualiza o maior numero
        if(numeros < numero_menor) numero_menor = numeros; // Atualiza o menor numero
        soma_media += numeros; // Atualiza a soma
        contador++; // Atualiza a contagem
    }

    // Calcula a media
    resultado = soma_media / contador;

    // Redireciona a saida para o arquivo twoquestionsaida.txt
    freopen("twoquestionsaida.txt", "w", stdout);
    printf("Menor numero: %.2f\n", numero_menor);
    printf("Maior numero: %.2f\n", numero_maior);
    printf("Media dos numeros: %.2f\n", resultado);

    // Fecha o arquivo
    if(!fclose(arquivo_entrada)){
        printf("Concluido\n");
    }
fclose(stdout);
    return 0;
}
