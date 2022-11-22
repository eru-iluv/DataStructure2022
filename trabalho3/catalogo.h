#ifndef CATALOGO_H
#define CATALOGO_H
#include "utils.h"
#include "jogo.h"
#define ERRO_CATALOGO -5000
extern int CATALOGO_MAX_SIZE;
typedef struct Catalogo CATALOGO;
CATALOGO *catalogo_criar();
boolean catalogo_apagar(CATALOGO **catalogo);
boolean catalogo_add_jogo(CATALOGO *catalogo, JOGO *jogo);
JOGO *catalogo_get_jogo(CATALOGO *catalogo, int indice);
JOGO** catalogo_get_todos_jogos(CATALOGO *catalogo);
int catalogo_tamanho(CATALOGO *catalogo);
void busca_catalogo_por_ano(CATALOGO *catalogo, int ano);
void busca_catalogo_por_produtora(CATALOGO *catalogo, char produtora[50]);
#endif
