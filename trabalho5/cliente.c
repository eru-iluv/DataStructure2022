#include "utils.h"
#include "cliente.h"

#include <stdlib.h>
#include <string.h>

struct Cliente
{
    char _cpf[11];
    char _cpfFormatado[14];
    char* _nome;
    int _idade;
    float _saldo;
};

CLIENTE* cliente_criar(char cpf[14], char* nome, int idade, float saldo)
{
    CLIENTE* cliente;
    char* pointerCpfTratado;

    cliente = (CLIENTE*) malloc(sizeof(CLIENTE));
    if (cliente != NULL) {

        pointerCpfTratado = treat_cpf(cpf);
        strcpy(cliente -> _cpf, pointerCpfTratado);
        strcpy(cliente ->_cpfFormatado, cpf);
        cliente -> _idade = idade;
        cliente -> _saldo = saldo;
        cliente -> _nome = (char*) malloc((strlen(nome) + 1)* sizeof(char));
        strcpy(cliente -> _nome, nome);

        free(pointerCpfTratado);
        return cliente;
    }
    return NULL;
}

boolean cliente_apagar(CLIENTE **cliente)
{
    if (*cliente != NULL) {
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
        printf("CPF :: %s\n", cliente -> _cpfFormatado);
        printf("Idade :: %d\n", cliente -> _idade);
        printf("Saldo atual :: %f", cliente -> _saldo);
    }
}
