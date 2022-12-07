#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#define ERROR_BINARY_TREE -5900
#include "utils.h"
#include "cliente.h"

typedef struct BinaryTree BT;
BT* binarytree_criar(CLIENTE* cliente);
boolean binarytree_apagar(BT **binaryTree);
boolean binarytree_atribuir_esquerda(BT* binaryTree, BT* arvoreEsquerda);
boolean binarytree_insere_filha(BT* binaryTree, BT* arvoreFilha);
#endif
