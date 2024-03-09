// Struct Aluno
typedef struct aluno Aluno;

// Função para criar um novo aluno.
// Retorna um ponteiro para a estrutura Aluno alocada.
Aluno* cria_Aluno(char nome[], int matricula);

// Função para matricular um aluno em uma disciplina. 
// Verifica se atingiu o limite de 10 disciplinas.
void matricula_disciplina(Aluno* aluno, Disciplina* disciplina);

// Função para solicitar os dados do aluno.
void Solicita_dados(Aluno* aluno);

// Função para liberar a memória alocada.
void exclui_aluno(Aluno* aluno);
