#include <stdio.h>
#include <stdlib.h>

int main(void){
    // Primeiro cria um arquivo com wt e depois para ler  os caracteres coloca r.
    FILE* arquivo_primeiro = fopen("onequestion.txt", "w");
    char** nome;
    int i;
    int max_alunos;
    float* nota1;
    float* nota2;
    float* nota3;
    float* media;
if(arquivo_primeiro == NULL){
    printf("Erro na entrada");
    exit(1);
}
else{
    printf("Feito\n");
}

printf("Digite o numero de alunos: \n");
scanf("%d", &max_alunos);
 // alocação.
nome = (char**)malloc(max_alunos * sizeof(char*));
for(i = 0; i < max_alunos; i++){
    nome[i] = (char*)malloc(80 * sizeof(char));
}

nota1 = (float*)malloc(max_alunos * sizeof(float));
nota2 = (float*)malloc(max_alunos * sizeof(float));
nota3 = (float*)malloc(max_alunos * sizeof(float));
media = (float*)malloc(max_alunos * sizeof(float));

    for(i = 0; i < max_alunos; i++){
        printf("Digite seu nome:\n");
        scanf("%s", nome[i]);
        printf("Digite a sua nota 1: \n");
        scanf("%f", &nota1[i]);
        printf("Digite a sua nota 2: \n");
        scanf("%f", &nota2[i]);
        printf("Digite a sua nota 3: \n");
        scanf("%f", &nota3[i]);

        media[i] = (nota1[i] + nota2[i] + nota3[i])/3;
        
    }

  // Imprimir as notas dos alunos 
    for(i = 0; i < max_alunos; i++){
        fprintf(arquivo_primeiro, "Nome: %s\t", nome[i]);
        fprintf(arquivo_primeiro, "Notas: %.2f, %.2f, %.2f\t", nota1[i], nota2[i], nota3[i]);
         if(media[i] >= 7.0){
            fprintf(arquivo_primeiro, "Aprovado. Sua media: %.2f\n", media[i]);
        }
        else{
            fprintf(arquivo_primeiro, "Reprovado\n");
        }
    }

if(!fclose(arquivo_primeiro)){
    printf("Fechado!!!\n");
}

for(i = 0; i < max_alunos; i++){
    free(nome[i]);
}
 free(nome);
 free(nota1);
  free(nota2);
   free(nota3);
    free(media);

return 0;
}
