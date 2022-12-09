#include "utils.h"
#include "big_numbers.h"
#include "cliente.h"

#include <stdlib.h>
#include <string.h>

struct Cliente
{
    BIGNUMBER* _cpf;
    char _cpfFormatado[15];
    char* _nome;
    int _idade;
    float _saldo;
};

CLIENTE* cliente_criar(char cpf[15], char* nome, int idade, float saldo)
{
    CLIENTE* cliente;
    char* treatedCpfPointer;
    char treatedCpf[11];
    BIGNUMBER* bigNumberCpf;


    cliente = (CLIENTE*) malloc(sizeof(CLIENTE));
    if (cliente != NULL) {

        treatedCpfPointer = treat_cpf(cpf);
        strcpy(treatedCpf, treatedCpfPointer);
        free(treatedCpfPointer);

        bigNumberCpf = bignumber_criar();
        bignumber_add_numero(bigNumberCpf, treatedCpf);

        cliente -> _cpf = bigNumberCpf;
        strcpy(cliente ->_cpfFormatado, cpf);
        cliente -> _idade = idade;
        cliente -> _saldo = saldo;
        cliente -> _nome = (char*) malloc(sizeof(nome));
        strcpy(cliente -> _nome, nome);

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

BIGNUMBER* cliente_get_cpf(CLIENTE* cliente)
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
