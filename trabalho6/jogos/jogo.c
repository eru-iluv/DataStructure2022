#include "jogo.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Jogo
{
    char _nome[50];
    char _produtora[50];
    int _ano;
};

JOGO *jogo_criar()
{
    JOGO *jogo;
    jogo = (JOGO *)malloc(sizeof(JOGO));
    if (jogo != NULL)
    {
        strcpy(jogo->_nome, "N/A");
        strcpy(jogo->_produtora, "N/A");
        jogo->_ano = -1;
    };
    return jogo;
};

boolean jogo_apagar(JOGO **jogo)
{
    if (*jogo != NULL)
    {
        free(*jogo);
        *jogo = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean jogo_add_nome(JOGO *jogo, char nome[50])
{
    if (jogo != NULL)
    {
        strcpy(jogo->_nome, nome);
        return TRUE;
    }
    return FALSE;
}

boolean jogo_add_produtora(JOGO *jogo, char produtora[50])
{
    if (jogo != NULL)
    {
        strcpy(jogo->_produtora, produtora);
        return TRUE;
    }
    return FALSE;
}

boolean jogo_add_ano(JOGO *jogo, int ano)
{
    if (jogo != NULL)
    {
        jogo->_ano = ano;
        return TRUE;
    }
    return FALSE;
}

char *jogo_get_nome(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->_nome;
    }
    return NULL;
}

void print_jogo(JOGO *jogo)
{
    if (jogo != NULL)
    {
        printf("%s\n", jogo->_nome);
    }
}

boolean jogo_maior(JOGO *jogo1, JOGO *jogo2)
{
    if (jogo1 != NULL && jogo2 != NULL)
    {
        if (jogo1->_ano == jogo2->_ano)
        {
            return str_maior(jogo1->_nome, jogo2->_nome); // Ordenação de Z a A
        }
        else
        {
            return jogo1->_ano > jogo2->_ano;
        }
    }

    return ERRO_UTILS;
}

int jogo_get_ano(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->_ano;
    }
    return -1;
}

char *jogo_get_produtora(JOGO *jogo)
{
    if (jogo != NULL)
    {
        return jogo->_produtora;
    }
    return NULL;
}
