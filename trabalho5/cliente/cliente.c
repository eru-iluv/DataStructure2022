#include "../utils/utils.h"
#include "cliente.h"

#include <stdlib.h>
#include <string.h>

struct Cliente
{
    char _cpf[15];
    char* _nome;
    int _idade;
    float _saldo;
};

CLIENTE* cliente_criar(char cpf[15], char* nome, int idade, float saldo)
{
    CLIENTE* cliente;

    cliente = (CLIENTE*) malloc(sizeof(CLIENTE));
    if (cliente != NULL) {

        strcpy(cliente -> _cpf, cpf);
        cliente -> _idade = idade;
        cliente -> _saldo = saldo;
        cliente -> _nome = (char*) malloc((strlen(nome) + 1)* sizeof(char));
        strcpy(cliente -> _nome, nome);

        return cliente;
    }
    return NULL;
}

boolean cliente_apagar(CLIENTE **cliente)
{
    if (*cliente != NULL) {
        free((*cliente) -> _nome);
        free(*cliente);
        *cliente = NULL;
        return TRUE;
    }

    return FALSE;
}

char* cliente_get_cpf(CLIENTE* cliente)
{
    return cliente -> _cpf;
}

void print_cliente(CLIENTE* cliente)
{
    if (cliente != NULL) {
        printf("Conta :: %s\n", cliente -> _nome);
        printf("CPF :: %s\n", cliente -> _cpf);
        printf("Idade :: %d\n", cliente -> _idade);
        printf("Saldo atual :: R$ %0.2f\n", cliente -> _saldo);
    }
}
