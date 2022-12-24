#include "utils/utils.h"
#include "malha_logistica/malha_logistica.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grafo/grafo.h"

int main()
{
    char *ponteiro;
    int numCidades;
    int numRotas;

    int x;
    int y;
    CIDADE cidade;
    ML* malha;

    // Primeiro, adicionamos as cidades à malha
    ponteiro = read_line();
    numCidades = atoi(ponteiro);
    malha = ml_criar(numCidades);
    free(ponteiro);


    for (int i = 0; i < numCidades; i++) {
        ponteiro = read_line();
        x = atoi(strtok(ponteiro,  ","));
        y = atoi(strtok(NULL, "\n"));
        free(ponteiro);

        cidade = (CIDADE) {x,y};
        ml_add_cidade(cidade, malha);
    }
    CIDADE origem;
    CIDADE destino;

    ponteiro = read_line();
    numRotas = atoi(ponteiro);
    free(ponteiro);

    // agora, adicionamos as rotas
    for (int i = 0; i < numRotas; i++) {
        ponteiro = read_line();
        x = atoi(strtok(ponteiro,  ","));
        y = atoi(strtok(NULL, ":"));

        origem = (CIDADE) {x,y};
        x = atoi(strtok(NULL, ","));
        y = atoi(strtok(NULL, "\n"));
        destino = (CIDADE) {x,y};

        ml_add_rota(origem, destino, malha);
        free(ponteiro);
    }


    // Agora é só apresentar os resultados
    ml_floyd_warshall(malha);

    print_cidade(ml_get_mais_central(malha));
    print_cidade(ml_get_mais_periferica(malha));
    print_cidade(ml_get_mais_distante_da_periferia(malha));

    ml_apagar(&malha);

}
