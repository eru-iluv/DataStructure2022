#ifndef MALHA_LOGISTICA_H
#define MALHA_LOGISTICA_H
#define ERRO_MALHA_LOGISTICA -6100
#include "../grafo/grafo.h"
#include "../utils/utils.h"

typedef struct VERTICE CIDADE;
typedef struct MalhaLogistica ML;

ML* ml_criar(int nVertices);
void ml_apagar(ML** ml);

boolean ml_add_cidade(CIDADE cidade, ML* malha);
boolean ml_add_rota(CIDADE origem, CIDADE destino, ML* malha);
boolean ml_remove_rota(CIDADE origem, CIDADE destino, ML* malha);

boolean ml_floyd_warshall(ML* malha);
CIDADE ml_get_mais_central(ML* malha);
CIDADE ml_get_mais_periferica(ML *malha);
CIDADE ml_get_mais_distante_da_periferia(ML* malha);

void print_cidade(CIDADE cidade);
void print_malha(ML* malha);
#endif
