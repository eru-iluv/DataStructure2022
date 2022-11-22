#ifndef POKEDEX_H
#define POKEDEX_H
#include "pokemon.h"
#include "utils.h"
#define ERRO_POKEDEX -4700
#define NUM_OF_POKEMON 151
typedef struct Pokedex POKEDEX;
POKEDEX *pokedex_criar();
boolean pokedex_apagar(POKEDEX **pokedex);
boolean pokedex_add_pokemon(POKEDEX *pokedex, POKEMON *pokemon);
POKEMON *pokedex_get_pokemon(POKEDEX *pokedex, int indice);

#endif
