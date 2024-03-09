#include <stdio.h>
#include <stdlib.h>
#include "contabancarioo.h" // Inclua o arquivo de cabeçalho

int main(){
    printf("Bem vindo!\n");

    // Crie uma nova conta
    Contabancaria* minhaConta = criarconta();

    // Deposite algum dinheiro na conta
    deposita(minhaConta);

    // Saque algum dinheiro da conta
    saca_saldo(minhaConta);

    // Imprima o saldo da conta
    printf("Saldo: %.2f\n", saldo(minhaConta));

    // Exclua a conta
    excluiConta(minhaConta);

    return 0;
}
/*
Questão 1) Crie um TAD chamado ContaBancaria que possui os seguintes campos: titular,
número e saldo. Como operações, considere as seguintes:
 Cria conta: aloca dinamicamente uma estrutura do tipo ContaBancaria e retorna seu
endereço. Os campos titular, número e saldo devem ser fornecidos como parâmetros;
 Deposita: recebe, como parâmetros, o endereço de uma estrutura do tipo
ContaBancaria e um valor, atualizando o saldo;
 Saca: recebe, como parâmetros, o endereço de uma estrutura do tipo ContaBancaria e
um valor, atualizando o saldo. Verificar se o saldo é suficiente para realizar o saque;
 Transfere: recebe, como parâmetros, os endereços das estruturas do tipo
ContaBancaria e um valor, atualizando os saldos. Verificar se o saldo é suficiente para
realizar a transferência;
 Saldo: recebe o endereço de uma estrutura do tipo ContaBancaria e retorna seu saldo;
 Exclui conta: libera o espaço alocado dinamicamente para a estrutura.
Faça o que se pede nos itens a seguir:
a) Crie um arquivo (contabancaria.h) com a interface do TAD.
b) Crie um arquivo (contabancaria.c) com a implementação do TAD.
c) Crie um programa que utiliza o TAD ContaBancaria. 
*/