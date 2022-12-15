#include "grafo.h"
#include "stdio.h"
#include "stdlib.h"
#define MAXNUMVERTICES 100

struct Vertice
{
    int x;
    int y;
};


struct Grafo
{
    int _nVertices;
    int _nArestas;
    int _matrizAdj[MAXNUMVERTICES][MAXNUMVERTICES];
};

boolean vertice_iguais(VERTICE v1, VERTICE v2)
{
    if (v1.x == v2.x && v1.y == v2.y){
        return TRUE;
    }
    return FALSE;
}

GRAFO* grafo_criar(int nVertices)
{
    GRAFO* grafo;
    grafo = (GRAFO*) malloc(sizeof(GRAFO));

    grafo -> _nVertices = nVertices;

    for (int i = 0; i < nVertices; i++)
    {
        for (int j = 0; j < nVertices; j++)
        {
            grafo -> _matrizAdj[i][j] = 0;
        }
    }

    grafo -> _nArestas = 0;

    return grafo;
}

void grafo_apagar(GRAFO** grafo)
{
    if (*grafo != NULL){
        free(*grafo);
        *grafo  = NULL;
    }
}

boolean grafo_add_vertice(VERTICE vertice, GRAFO *grafo)
{

}

boolean grafo_add_aresta(VERTICE fonte, VERTICE pia, int peso, GRAFO *grafo)
{

}
