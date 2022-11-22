#include <stdlib.h>
#include <stdio.h>
#include "atributos.h"
#include "utils.h"

struct Atributos {
    int _hp;
    int _ataque;
    int _defesa;
    int _ataque_especial;
    int _defesa_especial;
    int _velocidade;
};

ATRIBUTOS *atributos_criar(){
    ATRIBUTOS *atributos;
    atributos = (ATRIBUTOS *) malloc(sizeof(ATRIBUTOS));
    if (atributos != NULL)
    {
        atributos->_hp = -1;
        atributos->_ataque = -1;
        atributos->_defesa = -1;
        atributos->_ataque_especial = -1;
        atributos->_defesa_especial = -1;
        atributos->_velocidade = -1;
        return atributos;
    }
    return NULL;
}

boolean atributos_apagar(ATRIBUTOS **atributos)
{
    if (*atributos != NULL)
        {
            free(*atributos);
            *atributos = NULL;
            return TRUE;
        }
    return FALSE;
}

boolean atributos_hp(ATRIBUTOS *atributos, int hp)
{
    if (atributos != NULL && (MIN_STAT <= hp && hp <= MAX_STAT)){
        atributos->_hp = hp;
        return TRUE;
    }
    else if (!(MIN_STAT < hp && hp < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}
boolean atributos_defesa(ATRIBUTOS *atributos, int defesa)
{
    if (atributos != NULL && (MIN_STAT < defesa && defesa < MAX_STAT)){
        atributos->_defesa = defesa;
        return TRUE;
    }
    else if (!(MIN_STAT < defesa && defesa < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}
boolean atributos_ataque(ATRIBUTOS *atributos, int ataque)
{
    if (atributos != NULL && (MIN_STAT < ataque && ataque < MAX_STAT)){
        atributos->_ataque = ataque;
        return TRUE;
    }
    else if (!(MIN_STAT < ataque && ataque < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}

boolean atributos_ataque_especial(ATRIBUTOS *atributos, int ataque_especial)
{
    if (atributos != NULL && (MIN_STAT < ataque_especial && ataque_especial < MAX_STAT)){
        atributos->_ataque_especial = ataque_especial;
        return TRUE;
    }
    else if (!(MIN_STAT < ataque_especial && ataque_especial < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}
boolean atributos_defesa_especail(ATRIBUTOS *atributos, int defesa_especial)
{
    if (atributos != NULL && (MIN_STAT < defesa_especial && defesa_especial < MAX_STAT)){
        atributos->_defesa_especial = defesa_especial;
        return TRUE;
    }
    else if (!(MIN_STAT < defesa_especial && defesa_especial < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}
boolean atributos_velocidade(ATRIBUTOS *atributos, int velocidade)
{
    if (atributos != NULL && (MIN_STAT < velocidade && velocidade < MAX_STAT)){
        atributos->_velocidade = velocidade;
        return TRUE;
    }
    else if (!(MIN_STAT < velocidade && velocidade < MAX_STAT)) {
        return ERRO_ATRIBUTOS;
    }
    return FALSE;
}

void atributos_print(ATRIBUTOS *atributos)
{
    printf("Status:\n");
    printf("\tHP: %d\n", atributos -> _hp);
    printf("\tAtaque: %d\n", atributos -> _ataque);
    printf("\tDefesa: %d\n", atributos -> _defesa);
    printf("\tAtaque Especial: %d\n", atributos -> _ataque_especial);
    printf("\tDefesa Especial: %d\n", atributos -> _defesa_especial);
    printf("\tVelocidade: %d\n\n", atributos -> _velocidade);
}
