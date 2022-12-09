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

// retorna true se o cpf de cliente1 é maior que o de cliente2 e false
// no caso contrário
boolean cliente_compara_cpfs(CLIENTE* cliente1, CLIENTE* cliente2)
{
    if (cliente1 != NULL && cliente2 != NULL) {
        return bignumber_maior_que(cliente1 -> _cpf, cliente2 -> _cpf);
    }

    return ERRO_GENERICO;
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
