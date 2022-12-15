#ifndef MALHA_LOGISTICA_H
#define MALHA_LOGISTICA_H
#define ERRO_MALHA_LOGISTICA -6100
#include "../grafo/grafo.h"
#include "../utils/utils.h"

boolean vertice_iguais(VERTICE v1, VERTICE v2)
{
    if (v1.x == v2.x && v1.y == v2.y){
        return TRUE;
    }
    return FALSE;
}


typedef struct Cidade CIDADE;
typedef struct MalhaLogistica ML;

ML* ml_criar(int nVertices);
void ml_apagar(ML** ml);

boolean ml_add_cidade(VERTICE, ML* ml);

boolean ml_add_(VERTICE fonte, VERTICE pia, int peso, GRAFO* grafo);
boolean ml_remove_aresta(VERTICE fonte, VERTICE pia);

bo

#endif
