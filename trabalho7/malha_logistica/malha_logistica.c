#include "malha_logistica.h"
#include "../grafo/grafo.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"


struct MalhaLogistica
{
    int _nCidades;
    CIDADE* _cidades;
    GRAFO* _grafo;
    float** _matrizDistancias;
};

// Eu me arrependo de não ter usado distancia
// quadrada com int, mas acontece!
float cidades_distancia(CIDADE c1, CIDADE c2)
{
    float xRelativo = c2.x - c1.x;
    float yRelativo = c2.y - c1.y;

    return sqrt(xRelativo*xRelativo + yRelativo*yRelativo);
}

boolean cidades_iguais(CIDADE c1, CIDADE c2)
{
    if (c1.x == c2.x && c1.y == c2.y){
        return TRUE;
    }
    return FALSE;
}


ML* ml_criar(int nVertices)
{
    ML* malha;
    GRAFO* grafo;

    grafo = grafo_criar(nVertices);
    malha = (ML*) malloc(sizeof(ML));

    malha -> _nCidades = 0;
    malha -> _cidades = (CIDADE*) malloc(nVertices* sizeof(CIDADE));
    malha -> _grafo = grafo;
    malha -> _matrizDistancias = NULL;

    return malha;
}

void ml_apagar(ML **ml)
{
    if (*ml == NULL) {
        return;
    }

    free((*ml) -> _cidades);

    grafo_apagar(&(*ml) -> _grafo);
    for (int i = 0; i < (*ml) -> _nCidades; i++) {
        free((*ml) ->_matrizDistancias[i]);
    }
    free((*ml) -> _matrizDistancias);

    free(*ml);
    *ml = NULL;


}


// Não muito eficiente, mas como o número de cidades não
// fica muito grande, está ótimo
int ml_get_indice_by_cidade(CIDADE cidade, ML* malha)
{
    if (malha == NULL) {
        return -1;
    }

    int nCidades = malha -> _nCidades;
    for (int i = 0; i <= nCidades; i++) {
        if (cidades_iguais(cidade, malha -> _cidades[i]))
        {
            return i;
        }
    }

    return -1;
}


CIDADE ml_get_cidade_by_indice(int i, ML* malha)
{
    if (malha == NULL) {
        return (CIDADE) {-10000,-10000};
    }

    return malha -> _cidades[i];
}


boolean ml_add_cidade(CIDADE cidade, ML *malha)
{
    if (malha == NULL) {
        return FALSE;
    }

    // Esse ponteiro é meio overkill mas eu odeio
    // passar (tad -> propriedade).
    int* nCidades = &(malha -> _nCidades);

    malha -> _cidades[*nCidades] = cidade;
    *nCidades += 1;

    return TRUE;
};


boolean ml_add_rota(CIDADE origem, CIDADE destino, ML *malha)
{
    if (malha == NULL) {
        return FALSE;
    }

    float peso;
    int indiceOrigem;
    int indiceDestino;

    indiceOrigem = ml_get_indice_by_cidade(origem, malha);
    indiceDestino = ml_get_indice_by_cidade(destino, malha);

    peso = cidades_distancia(origem, destino);

    return grafo_add_aresta(indiceOrigem, indiceDestino, peso, malha -> _grafo);
}

boolean ml_remove_rota(CIDADE origem, CIDADE destino, ML *malha)
{
    if (malha == NULL) {
        return FALSE;
    }

    int indiceOrigem;
    int indiceDestino;

    indiceOrigem = ml_get_indice_by_cidade(origem, malha);
    indiceDestino = ml_get_indice_by_cidade(destino, malha);

    return grafo_remove_aresta(indiceOrigem, indiceDestino, malha -> _grafo);
}



boolean ml_floyd_warshall(ML* malha)
{
    if (malha == NULL){
        return FALSE;
    }
    malha -> _matrizDistancias = grafo_floyd_warshall(malha ->_grafo);
    return TRUE;
}

int get_indice_mais_central(ML* malha)
{
    int indiceCentro;
    float* maximosDistancia;
    int nCidades = malha -> _nCidades;
    int maxIndice;

    maximosDistancia = (float*) malloc(malha ->_nCidades* sizeof(float));
    for (int i = 0; i < nCidades; i++) {
        maxIndice = max_vetor_f(malha ->_matrizDistancias[i], nCidades);
        maximosDistancia[i] = malha -> _matrizDistancias[i][maxIndice];
    }


    indiceCentro = min_vetor_f(maximosDistancia, nCidades);
    free(maximosDistancia);
    return indiceCentro;
}

CIDADE ml_get_mais_central(ML* malha)
{

    if (malha == NULL || malha -> _matrizDistancias == NULL) {
        return (CIDADE) {ERRO_MALHA_LOGISTICA,ERRO_MALHA_LOGISTICA};
    }

    int indiceCidadeCentral;
    CIDADE cidadeCentral;

    indiceCidadeCentral = get_indice_mais_central(malha);
    cidadeCentral = ml_get_cidade_by_indice(indiceCidadeCentral, malha);

    return cidadeCentral;

}


int get_indice_mais_periferico(ML* malha)
{
    float* maximosDistancia;
    int nCidades = malha -> _nCidades;
    int maxIndice;
    int indicePeriferia;

    maximosDistancia = (float*) malloc(malha ->_nCidades* sizeof(float));
    for (int i = 0; i < nCidades; i++) {
        maxIndice = max_vetor_f(malha ->_matrizDistancias[i], nCidades);
        maximosDistancia[i] = malha -> _matrizDistancias[i][maxIndice];
    }

    indicePeriferia = max_vetor_f(maximosDistancia, nCidades);
    free(maximosDistancia);

    return indicePeriferia;
}

CIDADE ml_get_mais_periferica(ML* malha)
{

    if (malha == NULL || malha -> _matrizDistancias == NULL) {
        return (CIDADE) {ERRO_MALHA_LOGISTICA,ERRO_MALHA_LOGISTICA};
    }

    int indiceCidadePeriferica;
    CIDADE cidadePeriferica;

    indiceCidadePeriferica = get_indice_mais_periferico(malha);
    cidadePeriferica = ml_get_cidade_by_indice(indiceCidadePeriferica, malha);

    return cidadePeriferica;

}

int get_indice_distante_da_periferia(ML* malha)
{
    int nCidades = malha -> _nCidades;
    int indiceCidadePeriferica;
    int indiceCidadeMaisDistante;

    indiceCidadePeriferica = get_indice_mais_periferico(malha);
    indiceCidadeMaisDistante =
        max_vetor_f(malha ->_matrizDistancias[indiceCidadePeriferica], nCidades);

    return indiceCidadeMaisDistante;

}

CIDADE ml_get_mais_distante_da_periferia(ML* malha)
{

    if (malha == NULL || malha -> _matrizDistancias == NULL) {
        return (CIDADE) {ERRO_MALHA_LOGISTICA,ERRO_MALHA_LOGISTICA};
    }

    int indiceCidade;
    CIDADE cidade;

    indiceCidade = get_indice_distante_da_periferia(malha);
    cidade = ml_get_cidade_by_indice(indiceCidade, malha);

    return cidade;
}


void print_cidade(CIDADE cidade)
{
    printf("%d,%d\n", cidade.x, cidade.y);

}

void print_malha(ML* malha)
{
    print_grafo(malha -> _grafo);
}
