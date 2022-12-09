#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#define ERROR_BINARY_TREE -5900
#include "utils.h"
#include "cliente.h"

typedef struct BinaryTreeNode BT_NODE;
typedef struct BinaryTree BT;

BT* bt_criar();
boolean bt_apagar(BT** binaryTree);
boolean bt_insere_cliente(BT* binaryTree, CLIENTE* cliente);
boolean bt_remove_cliente(BT* binaryTree, char cpf[15]);
void bt_busca(BT* binaryTree, char cpf[15]);
#endif
