#include "pokemon.h"
#include "ataque.h"
#include "atributos.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pokemon {
  char _nome[50];
  char _tipo1[20];
  char _tipo2[20];
  ATRIBUTOS *_atributos;
  ATAQUE *_ataques[4];
  boolean _temTipoPrincipal;
};

POKEMON *pokemon_criar() {
  POKEMON *pokemon;
  pokemon = (POKEMON *)malloc(sizeof(POKEMON));
  if (pokemon != NULL) {
    strcpy(pokemon->_nome, "MISSIGNO");
    strcpy(pokemon->_tipo1, "");
    strcpy(pokemon->_tipo2, "");
    pokemon->_atributos = atributos_criar();
    pokemon->_temTipoPrincipal = FALSE;
    return pokemon;
  }
  return NULL;
}
boolean pokemon_apagar(POKEMON **pokemon) {
  if (*pokemon != NULL) {
    for (int i = 0; i < 4; i++) {
      ataque_apagar(&((*pokemon)->_ataques[i]));
    }
    atributos_apagar(&((*pokemon)->_atributos));
    free(*pokemon);
    *pokemon = NULL;
    return TRUE;
  }
  return FALSE;
}

boolean pokemon_add_name(POKEMON *pokemon, char nome[50]) {
  if (pokemon != NULL) {
    strcpy(pokemon->_nome, nome);
    return TRUE;
  }
  return FALSE;
}

boolean pokemon_add_ataque(POKEMON *pokemon, ATAQUE *ataque, int indice) {
  if (pokemon != NULL && indice < 4) {
    pokemon->_ataques[indice] = ataque;
    return TRUE;
  }
  return FALSE;
}

boolean pokemon_add_type(POKEMON *pokemon, char tipo[20]) {
  if (pokemon != NULL) {
    if (pokemon->_temTipoPrincipal) {
      strcpy(pokemon->_tipo2, tipo);
    } else {
      strcpy(pokemon->_tipo1, tipo);
      pokemon -> _temTipoPrincipal = TRUE;
    }
    return TRUE;
  }
  return FALSE;
}

boolean pokemon_atribui_hp(POKEMON *pokemon, int hp) {
  if (pokemon != NULL) {
    atributos_hp(pokemon->_atributos, hp);
    return TRUE;
  }
  return FALSE;
}
boolean pokemon_atribui_ataque(POKEMON *pokemon, int ataque) {
  if (pokemon != NULL) {
    atributos_ataque(pokemon->_atributos, ataque);
    return TRUE;
  }
  return FALSE;
}
boolean pokemon_atribui_defesa(POKEMON *pokemon, int defesa) {
  if (pokemon != NULL) {
    atributos_defesa(pokemon->_atributos, defesa);
    return TRUE;
  }
  return FALSE;
}
boolean pokemon_atribui_defesa_especial(POKEMON *pokemon, int defesa_especial) {
  if (pokemon != NULL) {
    atributos_defesa_especail(pokemon->_atributos, defesa_especial);
    return TRUE;
  }
  return FALSE;
}
boolean pokemon_atribui_ataque_especial(POKEMON *pokemon, int ataque_especial) {
  if (pokemon != NULL) {
    atributos_ataque_especial(pokemon->_atributos, ataque_especial);
    return TRUE;
  }
  return FALSE;
}
boolean pokemon_atribui_velocidade(POKEMON *pokemon, int velocidade) {
  if (pokemon != NULL) {
    atributos_velocidade(pokemon->_atributos, velocidade);
    return TRUE;
  }
  return FALSE;
}

void pokemon_print(POKEMON *pokemon) {
  printf("Nome do Pokemon: %s\n", pokemon->_nome);
  printf("Tipo primario: %s\n", pokemon->_tipo1);
  printf("Tipo secundario: %s\n", pokemon->_tipo2);
  atributos_print(pokemon->_atributos);
};

ATAQUE *pokemon_get_ataque(POKEMON *pokemon, int indice) {
  if (pokemon != NULL) {
    ATAQUE *ataque = pokemon->_ataques[indice];
    return ataque;
  }
  return NULL;
};
