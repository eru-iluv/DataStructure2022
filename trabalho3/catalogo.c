#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "jogo.h"
#include "catalogo.h"
#include <string.h>
int CATALOGO_MAX_SIZE = 50;

struct Catalogo
{
    JOGO** _listaJogo;
    int _tamanhoLista;
};

CATALOGO* catalogo_criar()
{
    CATALOGO *catalogo;
    catalogo = (CATALOGO*) malloc(sizeof(CATALOGO));
    if (catalogo != NULL)
    {
        catalogo -> _listaJogo =
            (JOGO**) malloc(CATALOGO_MAX_SIZE * sizeof(JOGO*));
        catalogo -> _tamanhoLista = -1;
        return catalogo;
    };
    return NULL;
};

boolean catalogo_apagar(CATALOGO **catalogo)
{
    if (*catalogo != NULL){
        for (int i = 0; i < (*catalogo) -> _tamanhoLista; i++) {
            jogo_apagar(&((*catalogo) -> _listaJogo[i]));
        }
        free((*catalogo) -> _listaJogo);
        free(*catalogo);
        *catalogo = NULL;
        return TRUE;
    }
    return FALSE;
};

boolean catalogo_add_jogo(CATALOGO *catalogo, JOGO *jogo)
{
    if (catalogo != NULL) {

        int *tamanho = &(catalogo -> _tamanhoLista);
         catalogo -> _listaJogo[*tamanho + 1] = jogo;
        (*tamanho)++;
    }
    return FALSE;
};

JOGO* catalogo_get_jogo(CATALOGO *catalogo, int indice)
{
    if (catalogo != NULL && (0 < indice && indice < catalogo -> _tamanhoLista))
    {
        JOGO *jogo;
        jogo = catalogo -> _listaJogo[indice];
        return jogo;
    } else if (indice < 0 || indice >= catalogo -> _tamanhoLista)
    {
        printf("INDICE INVÁLIDO");
        return NULL;
    };
    return NULL;
};

JOGO** catalogo_get_todos_jogos(CATALOGO *catalogo)
{
    return catalogo -> _listaJogo;
};

int catalogo_tamanho(CATALOGO *catalogo)
{
    return catalogo -> _tamanhoLista;
}

void busca_catalogo_por_produtora(CATALOGO *catalogo, char produtora[50])
{
    boolean encontrou_um = FALSE;
    if (catalogo != NULL) {
        for (int i = 0; i <= catalogo -> _tamanhoLista ; i++) {
            if (strcmp(jogo_get_produtora(catalogo -> _listaJogo[i]), produtora) == 0) {
                printf("%s\n", jogo_get_nome(catalogo -> _listaJogo[i]));
                !encontrou_um ? encontrou_um = TRUE : 0; // left side does nothing
            }
        }
        encontrou_um ? 0 : printf("Nada encontrado\n");
    }
}

void busca_catalogo_por_ano(CATALOGO *catalogo, int ano)
{
    boolean encontrou_um = FALSE;
    if (catalogo != NULL) {
        for (int i = 0; i <= catalogo -> _tamanhoLista ; i++) {
            if (jogo_get_ano(catalogo -> _listaJogo[i]) == ano) {
                printf("%s\n", jogo_get_nome(catalogo -> _listaJogo[i]));
                !encontrou_um ? encontrou_um = TRUE : 0; // left side does nothing
            }
        }
        encontrou_um ? 0 : printf("Nada encontrado\n");
    }
}
