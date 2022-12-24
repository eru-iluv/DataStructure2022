#ifndef AVL_TREE_H
#define AVL_TREE_H
#define ERRO_AVL_TREE -5900
#include "../utils/utils.h"
#include "../jogos/jogo.h"

typedef struct AvlTree AVL;
typedef struct AvlNode AVL_NODE;

AVL* avl_criar();
boolean avl_apagar(AVL** avlTree);


boolean avl_insere_jogo(AVL* avlTree, JOGO* jogo);
void avl_remove_jogo(AVL* avlTree, int ano);


void avl_busca(AVL* avlTree, int ano);
void avl_preordem(AVL* avlTree);
void avl_emordem(AVL* avlTree);
void avl_posordem(AVL* avlTree);
#endif
