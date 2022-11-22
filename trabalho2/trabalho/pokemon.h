#ifndef POKEMON_H
#define POKEMON_H
#include "atributos.h"
#include "ataque.h"
#include "utils.h"
#define ERRO_POKEMON -4500

typedef struct Pokemon POKEMON;
POKEMON *pokemon_criar();
boolean pokemon_apagar(POKEMON **pokemon);
boolean pokemon_add_ataque(POKEMON *pokemon, ATAQUE *ataque, int indice);
boolean pokemon_add_name(POKEMON *pokemon, char nome[50]);
boolean pokemon_add_type(POKEMON *pokemon, char tipo[20]);
boolean pokemon_atribui_hp(POKEMON *pokemon, int hp);
boolean pokemon_atribui_ataque(POKEMON *pokemon, int ataque);
boolean pokemon_atribui_defesa(POKEMON *pokemon, int defesa);
boolean pokemon_atribui_defesa_especial(POKEMON *pokemon, int defesa_especial);
boolean pokemon_atribui_ataque_especial(POKEMON *pokemon, int ataque_especial);
boolean pokemon_atribui_velocidade(POKEMON *pokemon, int velocidade);
void pokemon_print(POKEMON *pokemon);
ATAQUE* pokemon_get_ataque(POKEMON *pokemon, int indice);
#endif
