### Tipos Estruturados 

- São usados para definir novos tipos de dados.
- Os tipos estruturados permitem o agrupamento de informações em formato de variáveis em contextos para facilitar a sua manipulação.

## Mas antes, devemos entender o que são !!!
## STRUCT:
- Definição de Struct:
- Struct, é uma estrutura de dados que define de forma objetiva uma lista
 de variáveis agrupadas sob um nome no seu respectivo um bloco de memória.

- Sintaxe:
// Definir a estrutura
struct <identificador_ou_novo_tipo> {
   <listagem dos tipos e membros>;
};

// Usar a estrutura no main
int main() {
    struct <identificador_ou_novo_tipo> <variavel>;
    // ...
    return 0;
}
## Algumas observações:
- %[^\n]: Usado na função scanf. A seu objetivo é lê a até encontrar um caractere (\n). Isso é útil quando vamos ler uma linha inteira de texto, incluindo espaços.
- "->" : Usado para acessar membros de uma estrutura ou união através de um ponteiro.
. Por exemplo, se você tem um ponteiro p para uma estrutura que tem a variável x, teremos: p->x, no scanf.
- "." : Usado para acessar membros de uma estrutura ou união. 
. Por exemplo, se você tem uma estrutura s que tem um membro x, teremos s.x, no scanf.
- %2.f/%2.d : Usado no printf. Imprime um número, mas com pelo menos 2 dígitos preenchendo com zeros à esquerda caso precise.

- ## Exemplo de struct:
 #include <stdio.h>
struct ponto {
   float x, y;
};

int main(void) {
   struct ponto p;
   printf("Digite as coordenadas do ponto (x,y):");
   scanf("%f %f", &p.x, &p.y);
   printf("O ponto fornecido foi: (%.2f, %.2f)\n", p.x, p.y);

   return 0;
}
# Ponteiro para estruturas(STRUCT com ponteiros):
- Um ponteiro para uma estrutura contém o endereço de memória de uma variável. A variável é uma estrutura. Declaramos um ponteiro para a estrutura, assim:
- struct Ponto *pp; // ponteiro para ponteiro
- (*pp).x = 12.0; É equivalente a ->.
- pp->x = 12.0; //Acessar os membros de p através do ponteiro pp ->.

-- Exemplo:
struct Ponto {
    double x;
    double y;
};

int main() {
    // variável do tipo Ponto
    struct Ponto p;

    // um ponteiro para Ponto
    struct Ponto *pp;

    // pp apontar para p
    pp = &p;

    // Acessar p através de pp
    pp->x = 12.0;
    pp->y =  4.0;

    // Imprimir-los
    printf("O ponto é: (%.2f, %.2f)\n", pp->x, pp->y);

    return 0;
}
# Funções com estruturas:
- tipo_de_retorno nome_da_função (listagem de parâmetros) {
  informações;
  retorno_da_função;
}
- // Chamar no int main()
nome_da_função (listagem de parâmetros);

- As funções podem interagir com tipos estruturados de várias maneiras.
- Por exemplo, uma função pode aceitar uma estrutura como um argumento. 

#include <stdio.h>
struct ponto{
	float x, y;
};

void imprime (struct ponto *pp) {
	printf("O ponto fornecido foi: (%.2f, %.2f)\n", pp->x, pp->y);
}
void captura (struct ponto *pp) {
	printf("Digite as coordenadas do ponto (x,y):");
	scanf("%f %f", &pp->x, &pp->y);
}

int main(void){
	struct ponto p;
	captura(&p);
	imprime(&p);
	return 0;
}
# STRUCT na alocação:
- Podemons alocar dinâmicamente a struct de maneira clara e objetiva, veja agora um exemplo implementado do slide:

-#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura
struct Ponto {
    int x;
    int y;
};

int main() {
    // Declarando um ponteiro para a estrutura
    struct Ponto* p;

    // Alocando memória para a estrutura
    p = (struct Ponto*) malloc(sizeof(struct Ponto));

    // Verificando se a alocação foi bem-sucedida
    if (p == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1;
    }

    // Atribuindo valores aos campos da estrutura
    p->x = 10;
    p->y = 20;

    // Imprimindo os valores
    printf("Ponto: (%d, %d)\n", p->x, p->y);

    // Liberando a memória alocada
    free(p);

    return 0;
}

# TYPEDEF:
- typedef significa que estamos renomeando um tipo de dados para organização e o entendimento. Estamos nomeando
um tipo ou algo. 
- A sintaxe:
- typedef <nome do tipo de dado existente> <novo nome>;
- Com estruturas:
typedef struct ponto {
    int x;
    int y;
} Ponto;
typedef struct ponto Ponto;
typedef struct ponto *PPonto;
- Usando o mesmo typedef 
typedef struct ponto Ponto, *PPonto;  

- Com tipagens:
typedef int Inteiro;
typedef char Caractere;
typedef float Real;

# Unsigned 
- Unsigned é um modificador que é usado para alterar o comportamento dos tipos de dados inteiros. 
- Representa apenas valores não negativos.

- A sintaxe:
unsigned <nome do tipo de dado existente>

- Por exemplo, você pode ter unsigned int ou unsigned char.

- A função do unsigned  no código é permitir que um tipo de dados inteiro represente um intervalo maior de valores não negativos. 



- Exemplo:
#include <stdio.h>

int main() {
    unsigned int num = 4000000000;  // Um número maior que o máximo de um int normal
    printf("O valor de num é: %u\n", num);
    return 0;
}
# Aninhamento de Estruturas: 
- O aninhamento de estruturas ocorre quando uma estrutura é definida dentro de outra estrutura.
- Relaciona dados e agrupa eles em uma única estrutura.

// Esta estrutura representa um ponto no espaço.
struct ponto {
    float x;
    float y;
};

// Usando 'typedef' para criar um alias 'Ponto' para 'struct ponto'.
typedef struct ponto Ponto;

float distancia (Ponto* p, Ponto* q) {
    // Calcula a distância euclidiana entre os pontos 'p' e 'q' usando a fórmula da distância euclidiana.
    float d = sqrt((q->x - p->x)*(q->x - p->x) + (q->y - p->y)*(q->y - p->y));
    // Retorna o valor calculado da distância.
    return d;
}

# Comandos e observações:

- `%[^\n]`:
    - É usado com a função scanf para ler até encontrar \n. 
    - Para ler uma linhas do texto, incluindo espaços.
    - Sintaxe : scanf("%[^\n]", string);
 
-  `.`:
    - Explicação: O operador é usado para acessar membros de uma estrutura ou união.
    - Sintaxe: struct_variavel.membro

- `->`:
    - O operador é usado para acessar membros de uma estrutura ou união através de um ponteiro.
    - Sintaxe : struct_ponteiro->membro

