#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
#define ERROR_CLIENTE -5300
#include "utils.h"
#include "big_numbers.h"

typedef struct Cliente CLIENTE;
CLIENTE* cliente_criar(char cpf[15], char* nome, int idade, float saldo);
boolean cliente_apagar(CLIENTE **cliente);
BIGNUMBER* cliente_get_cpf(CLIENTE* cliente);
void print_cliente(CLIENTE* cliente);
#endif
