#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#define ERRO_BIGNUMBER -9000
#include "utils.h"

typedef struct BigNumber BIGNUMBER;
BIGNUMBER* bignumber_criar();
boolean bignumber_apagar(BIGNUMBER** bigNumber);
boolean bignumber_add_numero(BIGNUMBER *bigNumber, char *numero);
BIGNUMBER* bignumber_adicao(BIGNUMBER *bigNumber_1, BIGNUMBER *bigNumber_2);
boolean bignumber_igual(BIGNUMBER *bigNumber_1, BIGNUMBER *bigNumber_2);
boolean bignumber_print(BIGNUMBER *bigNumber);
boolean bignumber_maior_que(BIGNUMBER *bigNumber_1, BIGNUMBER * bigNumber_2);
boolean bignumber_menor_que(BIGNUMBER *bigNumber_1, BIGNUMBER *bigNumber_2);
#endif
