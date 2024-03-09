#include "contabancarioo.h" //Isso aqui representará a TAD
#include <stdlib.h>
#include <stdio.h>

Contabancaria* criarconta(){
    Contabancaria *contabancario = (Contabancaria *) malloc(sizeof(Contabancaria));

    printf("Insira o titular:\n");
    scanf("%s", contabancario->titular);
    printf("Insira o numero correspondente:\n");
    scanf("%d", &(contabancario->numero));
    printf("Insira o saldo:\n");
    scanf("%f", &(contabancario->saldo));

    return contabancario;
}
void deposita(Contabancaria *conta_deposito){
    float valor;
    printf("Quanto voce deseja depositar?\n");
    scanf("%f", &valor);

    char opcao;
    printf("Deseja depositar o valor %.2f na conta de %s? s - sim n - nao\n", valor, conta_deposito->titular);
    scanf(" %c", &opcao);
    if(opcao == 's'){
        conta_deposito->saldo += valor;
        printf("Depositado\n");
    }
}



void saca_saldo (Contabancaria *conta_deposito){
    float sacar;
    printf("Seu saldo %.2f\n", conta_deposito->saldo);
    printf("Quanto voce deseja sacar?\n");
    scanf("%f", &sacar);

    while(sacar > conta_deposito->saldo){
        printf("Valor acima do saldo\n");
        printf("Quanto voce deseja sacar?\n");
        scanf("%f", &sacar);
    }

    conta_deposito->saldo -= sacar;
    printf("Valor sacado: %.2f\n", sacar);
}

void transfere(Contabancaria *conta_deposito){
    float transfere;
    printf("Seu saldo %.2f\n", conta_deposito->saldo);
    printf("Quanto voce deseja transferir?\n");
    scanf("%f", &transfere);

    while(transfere > conta_deposito->saldo){
        printf("Valor acima do saldo\n");
        printf("Quanto voce deseja transferir?\n");
        scanf("%f", &transfere);
    }

    conta_deposito->saldo -= transfere;
    printf("Valor transferido: %.2f\n", transfere);
}

float saldo(Contabancaria *conta) {
    return conta->saldo;
}

void excluiConta(Contabancaria *conta) {
    free(conta);
    printf("Excluida!");
}

