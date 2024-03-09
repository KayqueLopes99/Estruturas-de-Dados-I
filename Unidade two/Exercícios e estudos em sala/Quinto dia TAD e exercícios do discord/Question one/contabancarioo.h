
typedef struct contabancario
{
    /* data */
    char titular[80];
    int numero;
    float saldo;
} Contabancaria;
Contabancaria* criarconta();
void deposita(Contabancaria *conta_deposito);
void saca_saldo (Contabancaria *conta_deposito);
void transfere(Contabancaria *conta_deposito);
float saldo(Contabancaria *conta);
void excluiConta(Contabancaria *conta);

