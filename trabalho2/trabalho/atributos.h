#ifndef ATRIBUTOS_H
#define ATRIBUTOS_H
#include "utils.h"
#define ERRO_ATRIBUTOS -4200
#define MAX_STAT 255
#define MIN_STAT 0
typedef struct Atributos ATRIBUTOS;
ATRIBUTOS *atributos_criar();
boolean atributos_apagar(ATRIBUTOS **atributos);
boolean atributos_hp(ATRIBUTOS *atributos, int hp);
boolean atributos_defesa(ATRIBUTOS *atributos, int defesa);
boolean atributos_ataque(ATRIBUTOS *atributos, int ataque);
boolean atributos_ataque_especial(ATRIBUTOS *atributos, int ataque_especial);
boolean atributos_defesa_especail(ATRIBUTOS *atributos, int defesa_especial);
boolean atributos_velocidade(ATRIBUTOS *atributos, int velocidade);
void atributos_print(ATRIBUTOS *atributos);
#endif
