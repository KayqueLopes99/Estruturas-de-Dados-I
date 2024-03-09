# gcc compiler
0. dir. verificação se os arquivos estão.
1. Compile o arquivo `operacao.c` para gerar o arquivo de objeto `operacao.o`:
```bash
gcc -c operacao.c
```
2. Compile o arquivo `TAREFAmain.c` para gerar o arquivo de objeto `TAREFAmain.o`:
```bash
gcc -c TAREFAmain.c
```
3. Vincule os arquivos de objeto `operacao.o` e `TAREFAmain.o` para criar um executável chamado `programa`:
```bash
gcc -o programa operacao.o TAREFAmain.o -lm
```
4. ./programanomeescolhido. sem espaços e _.

O `-lm` é necessário para vincular a biblioteca matemática devido ao uso da biblioteca `<math.h>` no seu código. 
