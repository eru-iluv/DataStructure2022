#ifndef GRAFO_H
#define GRAFO_H
#define ERROR_GRAFO -5900
#include "../utils/utils.h"

typedef struct Grafo GRAFO;

GRAFO* grafo_criar(int nVertices);
void grafo_apagar(GRAFO** grafo);

boolean grafo_add_aresta(int fonte, int ralo, int peso, GRAFO* grafo);
boolean grafo_remove_aresta(int fonte, int ralo);

boolean grafo_aresta_existe(int fonte, int ralo, GRAFO* grafo);
boolean vertice_tem_aresta(int fonte, int ralo, GRAFO* grafo);

#endif
