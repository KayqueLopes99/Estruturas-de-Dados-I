## Manipulação de arquivos.
. Função básica: 
- FILE* fopen(char* nome_arquivo, char* mado);

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

# fclose
. fechar um arquivo que foi aberto anteriormente pela função fopen. 
- O operador “!” inverte o valor retornado pela função fclose. Portanto, se o arquivo foi fechado com sucesso (retorno zero), a condição dentro do if será verdadeira. Nesse caso, o código exibirá a mensagem “Concluído”.
````c 
if (!fclose(arquivo) == 0){}
````

- Sintaxe:
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


. fscanf: 
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
### fgetc()
- A função fgetc() é usada para ler um caractere de um arquivo.

int fgetc(FILE *fp);
- O parâmetro fp é um ponteiro para o arquivo que será lido.

- Exemplo: lendo com a função fgetc()
- Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, o caractere 'A' é lido do arquivo. Por fim, o arquivo é fechado. Portanto, considerando que o arquivo "arquivo.txt" contenha apenas o caractere 'A', o programa imprimirá na tela o caractere 'A'.
`````c
#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    c = fgetc(fp); // Lê um caractere do arquivo
    printf("%c\n", c); // Imprime o caractere lido
    fclose(fp);

    return 0;
}
`````

### fputc()
- A função fputc() é usada para escrever um caractere em um arquivo.
int fputc(int c, FILE *fp);
- O primeiro parâmetro é o caractere que será escrito. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

- Exemplo: escrevendo com a função fputc()
Neste exemplo, o arquivo "arquivo.txt" é aberto para escrita. Em seguida, o caractere 'A' é escrito no arquivo. Por fim, o arquivo é fechado.
`````c
#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("arquivo.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputc('A', fp); // Escreve o caractere 'A' no arquivo apontado por fp
    fclose(fp);

    return 0;
}
`````

### feof()
- A função feof() é usada para verificar se o final de um arquivo foi atingido.
int feof(FILE *fp);
- O parâmetro fp é um ponteiro para o arquivo que será verificado.

- Exemplo: Veficando se chegamos ao final do arquivo
````` c
#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "r"); // Abre o arquivo
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (!feof(fp)) { // Enquanto não chegar ao final do arquivo
        c = fgetc(fp); // Lê um caractere do arquivo
        printf("%c", c); // Imprime o caractere lido
    }
    fclose(fp); // Fecha o arquivo

    return 0;
}
`````

### fgets()
- A função fgets() é usada para ler uma linha de um arquivo.
char *fgets(char *str, int n, FILE *fp);

- O primeiro parâmetro é um ponteiro para uma string que será usada para armazenar a linha lida. O segundo parâmetro é o número máximo de caracteres que podem ser lidos. O terceiro parâmetro é um ponteiro para o arquivo que será lido.

Exemplo: lendo com a função fgets()
- Neste exemplo, o arquivo "arquivo.txt" é aberto para leitura. Em seguida, uma linha do arquivo é lida e armazenada na string str. Por fim, o arquivo é fechado. Portanto, considerando que o arquivo "arquivo.txt" contenha apenas a linha "Hello World!", o programa imprimirá na tela a string "Hello World!".

````` c
#include <stdio.h>

int main() {
    FILE *fp;
    char str[100];

    fp = fopen("arquivo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fgets(str, 100, fp); // Lê uma linha do arquivo fp e armazena na string str com no máximo 100 caracteres
    printf("%s", str); // Imprime a string lida
    fclose(fp);

    return 0;
}
`````

## feof()
- A função feof() é usada para verificar se o final de um arquivo foi atingido.
````c
int feof(FILE *fp);`
````
- O parâmetro fp é um ponteiro para o arquivo que será verificado.

- Exemplo: 
```` c
#include <stdio.h>

int main() {
    FILE *fp;
    int c;

    fp = fopen("arquivo.txt", "r"); // Abre o arquivo
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    while (!feof(fp)) { // Enquanto não chegar ao final do arquivo
        c = fgetc(fp); // Lê um caractere do arquivo
        printf("%c", c); // Imprime o caractere lido
    }
    fclose(fp); // Fecha o arquivo

    return 0;
} 
````

### fputs()
- A função fputs() é usada para escrever uma string em um arquivo.
int fputs(const char *str, FILE *fp);

- O primeiro parâmetro é a string que será escrita. O segundo parâmetro é um ponteiro para o arquivo que será escrito.

- Exemplo: escrevendo com a função fputs()
- Neste exemplo, o arquivo "arquivo.txt" é aberto para escrita. Em seguida, a string "Hello World!" é escrita no arquivo. Por fim, o arquivo é fechado.
````` c

#include <stdio.h>

int main() {
    FILE *fp;

    fp = fopen("arquivo.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }
    fputs("Hello World!", fp); // Escreve a string "Hello World!" no arquivo apontado por fp
    fclose(fp);

    return 0;
}
`````

## LOGO 
- fgetc: Lê um único caractere de um arquivo de cada vez, incluindo espaços.
- fgets: Lê uma linha inteira de um arquivo de cada vez. Uma linha é definida como uma sequência de caracteres terminada por um caractere de nova linha (\n) ou pelo fim do arquivo.
- Ambas podem estar em um loop com EOF.

# Funções para escrever texto no arquivo:
A função fprintf em C é usada para escrever dados formatados em um arquivo.
A sintaxe:

```c
int fprintf(FILE *stream, const char *format [, argument ]...);
```

Agora, vamos entender cada parte:

1. `stream`: Este é o ponteiro para o arquivo onde você deseja escrever os dados. Ele indica qual arquivo receberá as informações formatadas.

2. `format`: É uma string de formato que especifica como os dados devem ser formatados. Você pode usar especificadores de formato, como `%d` para inteiros, `%f` para números de ponto flutuante, `%s` para strings, etc. Esses especificadores serão substituídos pelos valores reais quando você escrever no arquivo.

3. `argument`: São os valores que você deseja imprimir no arquivo, correspondentes aos especificadores de formato na string. Por exemplo, se você usar `%d` na string de formato, você deve fornecer um valor inteiro como argumento.

Aqui está um exemplo prático:

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






# Introdução.
. Encapsular de quem usa um determinado tipo a forma concreta
  com que ele foi implementado.
. Benefícios Desacoplamento da implementação do uso.

## Módulo 
# Módulos em C

- Encapsulação: A encapsulação esconde a implementação concreta de um determinado tipo de quem o utiliza.

- Desacoplamento: O desacoplamento da implementação do uso é uma das principais vantagens dos módulos em C.

## Tópicos Importantes

1. Definição de Módulos: Entender o que são módulos e como eles são estruturados em C. Isso inclui a compreensão de como os arquivos de cabeçalho (.h) e os arquivos de implementação (.c) trabalham juntos para formar um módulo.

2. Criação de Módulos: Aprender a criar seus próprios módulos. Isso envolve escrever arquivos de cabeçalho e implementação, bem como entender onde colocar declarações de funções, variáveis globais, definições de tipos e outras informações.

3. Uso de Módulos: Saber como incluir e usar módulos em seu código. Isso inclui o uso da diretiva `#include` e a compreensão de como o compilador lida com ela.

4. Proteção de Módulos: Entender como usar a diretiva `#ifndef` para evitar que um módulo seja incluído mais de uma vez.

5. Divisão de Código em Módulos: Aprender a dividir seu código em módulos lógicos para melhor organização e reutilização de código.

6. Compilação de Módulos: Compreender como compilar e vincular módulos juntos para formar um programa executável.

7. Módulos e Escopo: Entender como o escopo funciona com módulos, incluindo o conceito de variáveis globais e funções estáticas.

- Para Programas de médio e grande porte, a sua divisão em vários módulos é fundamental.
- str.c = Comprimento, copia, concatena. 
- Arquivo prog1.c
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
   