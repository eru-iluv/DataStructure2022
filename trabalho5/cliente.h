#ifndef CLIENTE_H
#define CLIENTE_H
#include <string.h>
#define ERROR_CLIENTE -5300
#include "utils.h"
#include "big_numbers.h"

typedef struct Cliente CLIENTE;
CLIENTE* cliente_criar(char cpf[15], char* nome, int idade, float saldo);
boolean cliente_apagar(CLIENTE **cliente);
boolean cliente_compara_cpfs(CLIENTE* cliente1, CLIENTE* cliente2);
BIGNUMBER* cliente_get_cpf(CLIENTE* cliente);
#endif
