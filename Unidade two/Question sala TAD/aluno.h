// renomear a struct: definição de um novo tipo.
// Função que aloca memória para um struct aluno, 
// recebe os dados via teclado e retorna um ponteiro para Aluno.

//Definição de novo tipo: Aluno
typedef struct aluno Aluno;
//Função que irá alocar memória para uma struct aluno, recebe dados via 
//teclado e retorna um ponteiro para Aluno
Aluno * recebe_dados(void);
//Função que exibe os dados do aluno
void exibe_aluno(Aluno * exibe);
void limpar(Aluno * aluno);