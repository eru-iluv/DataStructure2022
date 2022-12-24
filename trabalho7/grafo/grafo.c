#include "grafo.h"
#include "stdio.h"
#include "stdlib.h"

float grafo_peso(int i, int j, GRAFO* grafo);

struct Grafo
{
    int _nVertices;
    int _nArestas;
    float** _matrizAdj;
};

GRAFO* grafo_criar(int nVertices)
{
    if (nVertices < 2) {
        return NULL;
    }

    GRAFO* grafo;
    grafo = (GRAFO*) malloc(sizeof(GRAFO));
    if (grafo == NULL) return NULL;

    grafo -> _nVertices = nVertices;
    grafo -> _nArestas = 0;
    grafo -> _matrizAdj = (float**) malloc(nVertices*sizeof(float*));
    for (int i = 0; i < nVertices; i++) {
        grafo -> _matrizAdj[i] = (float*) malloc(nVertices*sizeof(float));
    }

    for (int i = 0; i < nVertices; i++)
    {
        for (int j = 0; j < nVertices; j++)
        {
            if (i != j){
                grafo -> _matrizAdj[i][j] = INF;
            } else {
                grafo -> _matrizAdj[i][j] = 0.0;
            }
        }
    }


    return grafo;
}

void grafo_apagar(GRAFO** grafo)
{
    if (*grafo != NULL){

        int nVertices = (*grafo) -> _nVertices;
        for (int i = 0; i < nVertices; i++)
        {
            free((*grafo) -> _matrizAdj[i]);
        }

        free((*grafo) -> _matrizAdj);
        free(*grafo);

        *grafo  = NULL;
    }
}

boolean grafo_add_aresta(int fonte, int ralo, int peso, GRAFO *grafo)
{

    if (grafo == NULL) {
        return FALSE;
    }
    int nVertices;
    nVertices = grafo -> _nVertices;
    if (fonte == ralo || fonte >= nVertices || ralo >= nVertices) {
        return FALSE;
    }

    grafo -> _nArestas += 1;
    grafo -> _matrizAdj[fonte][ralo] = peso;
    return TRUE;
}

boolean grafo_remove_aresta(int fonte, int ralo, GRAFO* grafo)
{
    if (grafo == NULL) {
        return FALSE;
    }
    int nVertices;
    nVertices = grafo -> _nVertices;
    if (fonte == ralo || fonte >= nVertices || ralo >= nVertices) {
        return FALSE;
    }

    grafo -> _nArestas -= 1;
    grafo -> _matrizAdj[fonte][ralo] = INF;
    return TRUE;
}

float grafo_peso(int fonte, int ralo, GRAFO* grafo)
{
    if (grafo == NULL) {
        return ERRO_GRAFO;
    }
    return grafo -> _matrizAdj[fonte][ralo];
}

float** grafo_floyd_warshall(GRAFO* grafo)
{
    if (grafo == NULL) {
        return NULL;
    }

    float** matrizDistancia;
    int nVertices;

    nVertices = grafo -> _nVertices;

    matrizDistancia = (float**)malloc(nVertices* sizeof(float*));
    if (grafo == NULL) return NULL;

    
    for (int i = 0; i < nVertices; i++) {
        matrizDistancia[i] = (float*) malloc(nVertices* sizeof(float));
    }


    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            matrizDistancia[i][j] = grafo_peso(i, j, grafo);
        }
    }
    for (int k = 0; k < nVertices; k++) {
        for (int i = 0; i < nVertices; i++) {
            for (int j = 0; j < nVertices; j++) {

                matrizDistancia[i][j]
                    = minf(matrizDistancia[i][j], matrizDistancia[i][k] + matrizDistancia[k][j]);

            }
       }
    }

    return matrizDistancia;

}

// função não usada mas bendita!!
void print_distancias(float** matrizDistancia, int nVertices)
{
    for (int i = 0; i < nVertices; i++) {
        for (int j = 0; j < nVertices; j++) {
            if (matrizDistancia[i][j] == INF) {
                printf(" INF ");
            }
            else {
                printf(" %0.1f ", matrizDistancia[i][j]);
            }
        }

        printf("\n");
    }

}

void print_grafo(GRAFO* grafo){
    if (grafo == NULL) {
        return;
    }

    int nVertices = grafo -> _nVertices;

    print_distancias(grafo -> _matrizAdj, nVertices);
}
