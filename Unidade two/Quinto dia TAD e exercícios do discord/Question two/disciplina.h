
// A struct.
typedef struct armazenador_de_dados_disciplina Disciplina;

// Função para solicitar a diciplina.
Disciplina* Solicita_disciplina();

// Função cria e aloca.
Disciplina* cria_disciplina(char nome[], int codigo);

// Função para deletar e liberar.
void exclui_disciplina(Disciplina* disciplina);

