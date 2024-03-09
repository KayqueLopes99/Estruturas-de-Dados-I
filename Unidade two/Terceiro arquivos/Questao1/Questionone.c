/*
Questão 1) Escreva um programa em C que leia de um arquivo as notas dos alunos de uma
turma e escreva em outro arquivo o nome e a média de cada aluno, bem como a sua situação
(aprovado (média >= 7.0) ou reprovado). Tanto no arquivo de entrada quanto no de saída,
considere que os dados em cada linha estão separados por um caractere de tabulação ‘\t’. Para a
execução do programa com o arquivo de entrada “entrada_q3.txt”, deverá ser criado o arquivo
de saída “saída_q3.txt”, como ilustrado a seguir.

*/


#include <stdio.h>  
#include <stdlib.h> 

int main(void){  

    FILE* primeiro_arquivoentrada = fopen("onequestionentrada.txt", "r");  // Abre o arquivo 'onequestionentrada.txt' para leitura.
  
    float media = 0;  // Variável para armazenar a médias.
    char nome[80];  // Array de caracteres para armazenar o nome.
    float nota1, nota2, nota3; 

    if(primeiro_arquivoentrada == NULL){  // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo\n");  
        exit(1);  // Termina o programa em caso de erro.
    }

    else{
        printf("Arquivo aberto com sucesso\n");  
    }

    freopen("onequestionsaida.txt", "w", stdout);  // Redireciona a saída padrão para o arquivo 'onequestionsaida.txt'

    // Lê o arquivo enquanto não chegar ao final do arquivo (EOF).
    while(fscanf(primeiro_arquivoentrada, "%s %f %f %f", nome, &nota1, &nota2, &nota3) != EOF){
        media = (nota1 + nota2 + nota3)/3;  // Calcula a média das notas.

        printf("Nome: %s", nome);  
        if(media >= 7.0){  // Verifica se a média é maior ou igual a 7.0.
            printf("Aprovado. Sua media: %.2f\n", media);  
        }
        else{
            printf("Reprovado\n"); 
        }
    }

    if(fclose(primeiro_arquivoentrada) == 0){  // Fecha o arquivo e verifica se foi fechado corretamente.
         fclose(stdout);  // Fecha a saída padrão
        printf("Concluido\n");  
    }
   
    return 0;
}
