#ifndef NODE_H
#define NODE_H
#define ERRO_NODE -4400
#include "utils.h"
extern int NODE_SIZE;

typedef struct Node NODE;
NODE* node_criar();
boolean node_apagar(NODE **node);
boolean node_apagar_cadeia(NODE **node);
boolean node_add_link(NODE* node, NODE* link);
boolean node_add_trecho(NODE* node, int trecho);
boolean node_adicao(NODE* node_1, NODE* node_2, NODE* nodeResultado, boolean hasDifferentSigns);
boolean node_print(NODE* node);
NODE* node_get_link(NODE* node);
boolean node_cadeia_igual(NODE* node_1, NODE* node_2);
boolean node_cadeia_maior(NODE* node_1, NODE* node_2);
#endif
