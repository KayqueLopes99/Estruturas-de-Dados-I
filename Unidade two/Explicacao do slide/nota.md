## Manipulação de arquivos.
. Função básica: 
- FILE* fopen(const char* nome_arquivo, const char* modo);
-  FILE* nome_do arquivo = fopen("nome.txt", "letra correspondente");
# Modos de abertura de arquivo:
.a função `fopen` é usada para abrir um arquivo e ela aceita dois argumentos:
.o nome do arquivo e o modo de abertura.

1. "r" (read): Este modo abre um arquivo para leitura. O arquivo deve existir. A sintaxe seria `FILE *arquivo = fopen("nome_do_arquivo", "r");`.

2. "w" (write): Este modo abre um arquivo para gravação. Se o arquivo existir, seu conteúdo é apagado. Se o arquivo não existir, ele será criado. A sintaxe seria `FILE *arquivo = fopen("nome_do_arquivo", "w");`.

3. "a" (append): Este modo abre um arquivo para anexar dados no final. Se o arquivo não existir, ele será criado. A sintaxe seria `FILE *arquivo = fopen("nome_do_arquivo", "a");`.

4. O modo "t" (text) pode ser usado como um modificador para abrir o arquivo no modo texto.


# Testando abertura de arquivo 'FOPEN'
. Explicação:
.  A função `fopen` tenta abrir o arquivo com o nome e o modo especificados. 
.  Se a operação for bem-sucedida, ela retorna um ponteiro para  `FILE` que opera. Se a operação falhar, ela retorna `NULL`.

. Sintaxe geral:
FILE *fopen(const char *filename, const char *mode);

- filename: o nome do arquivo a ser aberto.
- mode: o modo de acesso de arquivo.

. Exemplo:
```
FILE *fp = fopen("meu_arquivo.txt", "r");
if (fp == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit (1);
}

// O arquivo foi aberto.
fclose(fp);  // Lembre-se: fechar o arquivo quando terminar.
```

# Funções para abrir e FCLOSE
. fechar um arquivo que foi aberto anteriormente pela função fopen. 

Sintaxe:
int fclose(FILE *stream);

. Exemplo:
```c
FILE *arquivo = fopen("exemplo.txt", "r");
if (arquivo != NULL) {
    // ... realizar operações no arquivo ...
    if (fclose(arquivo) == 0) {
        printf("Arquivo fechado com sucesso.\n");
    } else {
        printf("Erro ao fechar o arquivo.\n");
    }
} else {
    printf("Erro ao abrir o arquivo.\n");
}
```
- Pode usar no final também
- fclose(fopen); // fecha

# freopen e stdout
Útil quando você deseja redirecionar a saída de `printf`, que normalmente vai para `stdout` (a tela), para um arquivo.
.Redirecionar a saída de `printf` para um arquivo.

```c
// Redirecionar stdout para um arquivo
freopen("saida.txt", "w", stdout);

// Agora, printf escreverá no arquivo "saida.txt" em vez da tela
printf("Olá, Mundo!\n");

// Quando terminar, você pode fechar o arquivo e reabrir stdout
freopen(NULL, "w", stdout);
```
OU 

if(fclose(primeiro_arquivoentrada) == 0){
         fclose(stdout);
        printf("Concluido\n");
    }

. stdout é uma variável global em C que representa a "saída padrão" para a stream de saída.
```c
freopen("saida.txt", "w", stdout);
printf("Olá, Mundo!\n");  // Isso agora será escrito em "saida.txt"
```

# Leitura dos dados no arquivo


1. fscanf: 
. A função `fscanf` lê os dados do arquivo de acordo com o especificador de formato fornecido. 
. Faz retorno dos argumentos lidos com sucesso.

```c
int fscanf(FILE* fp, const char* formato, ...);
```

- Exemplo de uso:
```c
FILE *fp = fopen("arquivo.txt", "r");
int num;
fscanf(fp, "%d", &num);  // Lê um número inteiro do arquivo
fclose(fp);
```

2. fgetc:
.  A função `fgetc` lê o próximo caractere de um arquivo.
. Faz retorno do caractere lido como um `int` ou `EOF` se atingir o final ou erro.

```c
int fgetc(FILE* fp);
```
Exemplo de uso:
```c
FILE *fp = fopen("arquivo.txt", "r");
int c = fgetc(fp);  // Lê o primeiro caractere do arquivo
fclose(fp);
```

3. fgets: 
. A função `fgets` lê uma linha do arquivo especificado. 
. Ela lê até `n-1` caracteres ou até encontrar uma nova linha \n.
. Terminada com um caractere nulo (`\0`).

```c
char* fgets(char* s, int n, FILE* fp);
```
Exemplo de uso:
```c
FILE *fp = fopen("arquivo.txt", "r");
char str[60];
fgets(str, 60, fp);  // Lê a primeira linha (ou até 59 caracteres) do arquivo
fclose(fp);
```

# Funções para escrever texto no arquivo:
.  Ela pode ser usada para escrever em um arquivo.
.  A string formatada pode incluir especificadores de formato,`%d`, `%f` ... 

.Sintaxe geral:
```c
FILE *fp = fopen("arquivo.txt", "w");
if (fp != NULL) {
    int num = 123;
    fprintf(fp, "O número é: %d\n", num);
    fclose(fp);
} else {
    printf("Erro ao abrir o arquivo.\n");
}
```
# Introdução
. Encapsular de quem usa um determinado tipo a forma concreta
  com que ele foi implementado.
. Benefícios Desacoplamento da implementação do uso.

## Módulo 
- Arquivo com funções que representam parte de uma implementação.
-  Aimplementação é composta por mais de um módulo.

- Vários módulos = (.o ou .obj).
- Ligador (linker).

. Para Programas de médio e grande porte, a sua divisão em vários módulos é fundamental.
. str.c = Comprimento, copia, concatena. 
. Arquivo prog1.c
``` c
int comprimento (char* s){
int i;
int n = 0;/* contador */
for(i = 0; s[i] != '0'; I++) //Enquanto não chega ao fim emcremente.
{
n++;
}
 
    return n;
}
 
void copia (char* dest, char* orig){
    int i;
    for (i = 0; orig[i] != '\0'; i++){
    dest[i] = orig[i];
    }
    /* fecha a cadeira copiada */
    dest[i] = '\0';
}
 
void concatena (char* dest, char* orig) {
    int i = 0;
    // índice usado na cadeira destino, iniciando com zero.
    int j; 
    // Índice usado na cadeia origem.
    //  Acha o final da cadeia destino.
    while[i] != '/0'
}
// Continuar
 ```


## Observações no .h 
- #ifdef e #ifndef:
   - Elas são frequentemente usadas para criar guardas de inclusão (include guards) em arquivos de cabeçalho para evitar múltiplas inclusões acidentais do mesmo arquivo.
   - A ideia é que, se o símbolo já foi definido, o código dentro do bloco #ifdef será incluído; caso contrário, ele será ignorado.

- Exemplo:
   Suponha que temos um arquivo de cabeçalho chamado meu_header.h. Queremos garantir que ele seja incluído apenas uma vez em nosso código-fonte. Podemos fazer o seguinte:

   ```c
   // meu_header.h

   #ifndef MEU_HEADER_H // Verifica se MEU_HEADER_H não está definido
   #define MEU_HEADER_H // Define MEU_HEADER_H para evitar múltiplas inclusões

   // Conteúdo do arquivo de cabeçalho aqui

   #endif // Fim do bloco de inclusão
   ```

   No código-fonte (por exemplo, `main.c`), incluímos o arquivo da seguinte maneira:

   ```c
   #include "meu_header.h"
   // Resto do código
   ```
   
