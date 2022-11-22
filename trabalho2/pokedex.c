#include <stdlib.h>
#include <stdio.h>
#include "ataque.h"
#include "utils.h"
#include "pokemon.h"
#include "pokedex.h"
struct Pokedex
{
    POKEMON** _lista_pokemon;
    int _tamanho_lista;
};

POKEDEX *pokedex_criar()
{
    POKEDEX *pokedex;
    pokedex = (POKEDEX *) malloc(sizeof(POKEDEX));
    if (pokedex != NULL)
    {
        pokedex -> _lista_pokemon = (POKEMON**) malloc(151 * sizeof(POKEMON*));
        pokedex -> _tamanho_lista = 0;
        return pokedex;
    }
    return NULL;
};
boolean pokedex_apagar(POKEDEX **pokedex)
{
    if (*pokedex != NULL){
        for (int i = 0; i < (*pokedex) -> _tamanho_lista; i++) {
            pokemon_apagar(&((*pokedex) -> _lista_pokemon[i]));
        }
        free((*pokedex) -> _lista_pokemon);
        free(*pokedex);
        *pokedex = NULL;
        return TRUE;
    }
    return FALSE;
}


boolean pokedex_add_pokemon(POKEDEX *pokedex, POKEMON *pokemon)
{
    if (pokedex != NULL) {

        int *tamanho = &(pokedex -> _tamanho_lista);
         pokedex -> _lista_pokemon[*tamanho] = pokemon;
        (*tamanho)++;
    }
    return FALSE;
};

POKEMON *pokedex_get_pokemon(POKEDEX *pokedex, int indice)
{
    POKEMON *pokemon;
    if (pokedex != NULL && indice < pokedex -> _tamanho_lista) {
        pokemon = pokedex -> _lista_pokemon[indice];
        return pokemon;
    } else if (indice == pokedex -> _tamanho_lista)
    {
        printf("Indíce maior que a quantidade de pokemons brrrr");
        return FALSE;
    }
    return FALSE;
};
