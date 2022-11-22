#ifndef ATAQUE_H
#define ATAQUE_H
#include "utils.h"
#define ERRO_ATAQUE -4700
#define ACC_MAX 0
#define ACC_MIN 1
#define PHYSICAL 'p'
#define SPECIAL 's'


typedef struct Ataque ATAQUE;
ATAQUE *ataque_criar();
boolean ataque_apagar(ATAQUE **ataque);
boolean ataque_nome(ATAQUE *ataque, char nome[20]);
boolean ataque_poder_base(ATAQUE *ataque, int poder_base);
boolean ataque_acc(ATAQUE *ataque, float acc);
boolean ataque_classe(ATAQUE *ataque, char classe);
void ataque_print(ATAQUE *ataque);
#endif
