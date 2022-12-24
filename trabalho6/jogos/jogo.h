#ifndef JOGO_H
#define JOGO_H
#define ERRO_JOGO -4400
#include "../utils/utils.h"

typedef struct Jogo JOGO;
JOGO *jogo_criar();
boolean jogo_apagar(JOGO **jogo);

boolean jogo_add_nome(JOGO *jogo, char nome[50]);
boolean jogo_add_produtora(JOGO *jogo, char produtora[50]);
boolean jogo_add_ano(JOGO *jogo, int ano);

char* jogo_get_nome(JOGO *jogo);
char* jogo_get_produtora(JOGO *jogo);
int jogo_get_ano(JOGO *jogo);

boolean jogo_maior(JOGO* jogo1, JOGO* jogo2);
void print_jogo(JOGO *jogo);

#endif
