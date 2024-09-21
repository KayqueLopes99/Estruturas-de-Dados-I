// Struct
typedef struct _fila Fila;
// Função CRIAÇÃO.
Fila * CriaFila(int MAX_SIZE);
// Função LIBERAR.
void DestruirFila(Fila **Q);
// Função Verifica Vazio.
int Fila_vazia(Fila * Q);
// Função Fila Cheia.
int Fila_cheia(Fila * Q);
// Função Insere.
int InsereFila(Fila *Q, int elemento);
// Função remover.
int RemoveFila(Fila *Q);
// Função Consulta.
int ConsultaFila(Fila *Q, int *elemento);