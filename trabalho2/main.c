#include "ataque.h"
#include "pokedex.h"
#include "pokemon.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void cadastrar_pokemon(POKEDEX *pokedex);
void adicionar_ataque(POKEDEX *pokedex);
void imprimir_pokemon(POKEDEX *pokedex);
void imprimir_ataque(POKEDEX *pokedex);
int main(void) {
  POKEDEX *pokedex = pokedex_criar();
  int order = -1;
  while (order != 0) {
    order = -1;
    scanf("%d", &order);

    switch (order) {
    case 1:
      cadastrar_pokemon(pokedex);
      break;
    case 2:
      adicionar_ataque(pokedex);
      break;
    case 3:
      imprimir_pokemon(pokedex);
      break;
    case 4:
      imprimir_ataque(pokedex);
      break;
    default:
      order = 0;
      break;
  }
  }
  if (order == 0) {
    pokedex_apagar(&pokedex);
    return 0;
  }
  return -1;
};
void cadastrar_pokemon(POKEDEX *pokedex) {
  char nome[50];
  char tipo1[20];
  char tipo2[20];
  int hp;
  int ataque;
  int defesa;
  int ataque_especial;
  int defesa_especial;
  int velocidade;

  scanf("%s", nome);
  scanf("%s", tipo1);
  scanf("%s", tipo2);
  scanf("%d", &hp);
  scanf("%d", &ataque);
  scanf("%d", &defesa);
  scanf("%d", &ataque_especial);
  scanf("%d", &defesa_especial);
  scanf("%d", &velocidade);

  POKEMON *novo_pokemon = pokemon_criar();
  pokemon_add_name(novo_pokemon, nome);

  pokemon_add_type(novo_pokemon, tipo1);
  pokemon_add_type(novo_pokemon, tipo2);

  // ATRIBUTOS
  pokemon_atribui_hp(novo_pokemon, hp);
  pokemon_atribui_ataque(novo_pokemon, ataque);
  pokemon_atribui_defesa(novo_pokemon, defesa);
  pokemon_atribui_ataque_especial(novo_pokemon, ataque_especial);
  pokemon_atribui_defesa_especial(novo_pokemon, defesa_especial);
  pokemon_atribui_velocidade(novo_pokemon, velocidade);

  pokedex_add_pokemon(pokedex, novo_pokemon);
};

void adicionar_ataque(POKEDEX *pokedex) {
  if (pokedex != NULL) {
    int indice_pokemon = 0;
    int indice_ataque = 0;
    POKEMON *pokemon;
    ATAQUE *ataque;

    scanf("%d", &indice_ataque);
    pokemon = pokedex_get_pokemon(pokedex, indice_pokemon);
    scanf("%d", &indice_ataque);


    char nome[20];
    int poder_base;
    float acuracia;
    char classe;
    scanf("%s", nome);
    scanf("%d", &poder_base);
    scanf("%f", &acuracia);
    scanf(" %c", &classe);

    ataque = ataque_criar();
    ataque_nome(ataque, nome);
    ataque_poder_base(ataque, poder_base);
    ataque_acc(ataque, acuracia);
    ataque_classe(ataque, classe);

    pokemon_add_ataque(pokemon, ataque, indice_ataque);
  }
};

void imprimir_pokemon(POKEDEX *pokedex) {
  if (pokedex != NULL) {
    int indice;
    POKEMON *pokemon;

    scanf("%d", &indice);
    pokemon = pokedex_get_pokemon(pokedex, indice);
    pokemon != NULL ? pokemon_print(pokemon) : printf("Indice fora da pokedex");
  };
}

void imprimir_ataque(POKEDEX *pokedex) {
    if (pokedex != NULL)
    {
    int indice_pokemon = 0;
    int indice_ataque = 0;
    POKEMON *pokemon;
    ATAQUE *ataque;

    scanf("%d", &indice_ataque);
    pokemon = pokedex_get_pokemon(pokedex, indice_pokemon);
    scanf("%d", &indice_ataque);
    ataque = pokemon_get_ataque(pokemon, indice_ataque);

    ataque_print(ataque);
    }
}
