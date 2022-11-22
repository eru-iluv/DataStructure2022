#include "jogo.h"
#include "utils.h"
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
    jogo = (JOGO*)malloc(sizeof(JOGO));
    if (jogo != NULL) {
        strcpy(jogo -> _nome, "N/A");
        strcpy(jogo -> _produtora, "N/A");
        jogo -> _ano = -1;
    };
    return jogo;
};

boolean jogo_apagar(JOGO **jogo)
{
    if (*jogo != NULL){
        free(*jogo);
        *jogo = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean jogo_add_nome(JOGO *jogo, char nome[50])
{
  if (jogo != NULL) {
    strcpy(jogo->_nome, nome);
    return TRUE;
  }
  return FALSE;
}

boolean jogo_add_produtora(JOGO *jogo, char produtora[50])
{
  if (jogo != NULL) {
    strcpy(jogo->_produtora, produtora);
    return TRUE;
  }
  return FALSE;
}

boolean jogo_add_ano(JOGO *jogo, int ano)
{
  if (jogo != NULL) {
    jogo -> _ano = ano;
    return TRUE;
  }
  return FALSE;
}

char* jogo_get_nome(JOGO *jogo)
{
  if (jogo != NULL)
  {
    return jogo -> _nome;
  }
  return NULL;
}

int jogo_get_ano(JOGO *jogo)
{
  if (jogo != NULL)
  {
    return jogo -> _ano;
  }
  return -1;
}

char* jogo_get_produtora(JOGO *jogo)
{
  if (jogo != NULL)
  {
    return jogo -> _produtora;
  }
  return NULL;
}
