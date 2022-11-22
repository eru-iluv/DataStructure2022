#include <stdlib.h>
#include <stdio.h>
#include "ataque.h"
#include "utils.h"
#include <string.h>

struct Ataque {
    char _nome[20];
    int _poder_base;
    float _acc;
    char _classe;
};

ATAQUE *ataque_criar()
{
    ATAQUE *ataque;
    ataque = (ATAQUE *) malloc(sizeof(ATAQUE));
    if (ataque != NULL)
    {
        strcpy(ataque->_nome, "");
        ataque->_poder_base = -1;
        ataque->_acc = -1;
        ataque->_classe = '\n';
        return ataque;
    }
    return NULL;
};

boolean ataque_apagar(ATAQUE **ataque)
{
    if (*ataque != NULL)
        {
            free(*ataque);
            *ataque = NULL;
            return TRUE;
        }
    return FALSE;
};
boolean ataque_nome(ATAQUE *ataque, char nome[20])
{
    if (ataque != NULL){
        strcpy(ataque -> _nome, nome);
        return TRUE;
    }
    return FALSE;
};

boolean ataque_poder_base(ATAQUE *ataque, int poder_base)
{
    if (ataque != NULL){
        ataque -> _poder_base = poder_base;
        return TRUE;
    }
    return FALSE;
};
boolean ataque_acc(ATAQUE *ataque, float acc)
{
    if (ataque != NULL && (0 <= acc && acc <= 1)){
        ataque -> _acc = acc;
        return TRUE;
    } else if (!(ACC_MIN <= acc && acc <= ACC_MAX)) {
        return ERRO_ATAQUE;
    }
    return FALSE;
};
boolean ataque_classe(ATAQUE *ataque, char classe)
{
    if (ataque != NULL && (classe == PHYSICAL || classe == SPECIAL)){
        ataque -> _classe = classe;
        return TRUE;
    } else if (!(classe == PHYSICAL || classe == SPECIAL)) {
        return ERRO_ATAQUE;
    }
    return FALSE;
};

void ataque_print(ATAQUE *ataque)
{
    printf("Nome do Ataque: %s\n", ataque -> _nome);
    printf("Poder base: %d\n", ataque -> _poder_base);
    printf("Acuracia: %f\n", ataque -> _acc);
    printf("Classe: %c\n\n", ataque -> _classe);
};
