#include "big_numbers.h"
#include "utils.h"
#include "nodes.h"
#include <stdio.h>
#include <stdlib.h>

int NODE_SIZE = 4;     // Numeros de dígitos em um node
int MAX_TRECHO = 10000; // Tamanaho máximo do trecho de um node. Manter sempre como 10**NODE_SIZE.
boolean coloca_os_zeros_a_esquerda(NODE* node);
int node_atribui_trecho_resultado(NODE* node_1, NODE* node_2, NODE* nodeResultado, boolean hasDifferentSigns);

struct Node{
    int _trecho;
    NODE* _link;
};

NODE* node_criar(){
    NODE* node;
    node = (NODE*)malloc(sizeof(NODE));
    if (node != NULL) {
        node -> _trecho = 0;
        node -> _link = NULL;
        return node;
    }
    return NULL;
};

// Apaga apenas um node
boolean node_apagar(NODE** node){
    if (*node != NULL){
        free(*node);
        *node = NULL;
        return TRUE;
    }
    return FALSE;
}

// Apaga um node e seus filhos
boolean node_apagar_cadeia(NODE** node){
    if (*node != NULL) {
        if ((*node) -> _link != NULL) {
            node_apagar_cadeia(&((*node) -> _link));
        }
        free(*node);
        *node = NULL;
        return TRUE;
    }
    return FALSE;
}


boolean node_add_link(NODE* node, NODE* link){
    if (node != NULL) {
        node -> _link = link;
        return TRUE;
    }
    return FALSE;
}

boolean node_add_trecho(NODE* node, int trecho)
{
    if (node != NULL && 0 <= trecho && trecho < MAX_TRECHO){
        node -> _trecho = trecho;
        return TRUE;
    }
    else if (trecho >= MAX_TRECHO) {
        printf("\nERRO NODE: O valor inserido é maior que"
               "o tamanho máximo de um node (trecho > %d).\n", MAX_TRECHO-1);
    } else if (trecho < 0){
        printf("\nERRO NODE: O valor inserido é menor que 0.\n");
    }
    return FALSE;
};

NODE* node_get_link(NODE* node)
{
    if (node != NULL) {
        return node -> _link;
    }

    printf("\nERRO NODE: nodes vazios não podem ter links!!\n");
    return NULL;
}

boolean node_adicao(NODE* node_1, NODE* node_2, NODE* nodeResultado, boolean hasDifferentSigns)
{
    int trechoResultado;
    if (node_1 == NULL && node_2 == NULL) {
        printf("\nNODE ERROR: Não podemos somar dois termos nulos bobinho!\n");
        return FALSE;
    } else {
        trechoResultado = node_atribui_trecho_resultado(node_1, node_2, nodeResultado, hasDifferentSigns);
    }

    if (trechoResultado >= MAX_TRECHO) {
        trechoResultado = trechoResultado % MAX_TRECHO;
        node_add_trecho(nodeResultado, trechoResultado);
        return TRUE;
    }

    node_add_trecho(nodeResultado, trechoResultado);

    return FALSE;

    
}

boolean node_maior_menor_igual(NODE* node_1, NODE* node_2){
            if (node_1 -> _trecho == node_2 -> _trecho) {
                return -1;
            } else if (node_1 -> _trecho > node_2 -> _trecho) {
                return TRUE;
            } else {
                return FALSE;
            }
}

/*
** ----- FUNÇÃO RECURSIVA : node_cadeia_igual -----
** TERMO DE RECURSÃO:
**  Se os trechos são iguais, chamamos a função em seus links
**
** CASOS BASE:
**  FALSE: Chegamos em em trechos diferentes
**  TRUE: Chegamos no final da cadeia, e os trechos continuam iguais
 */
boolean node_cadeia_igual(NODE* node_1, NODE* node_2)
{
    if (node_1 != NULL && node_2 != NULL) {
        if ( (node_1 -> _trecho) != (node_2 -> _trecho) ) {
            return FALSE;
        } else if ( (node_1 -> _trecho) == (node_2 -> _trecho) ) {
            if ((node_1 -> _link == NULL) && (node_2 -> _link == NULL) ) {
                return TRUE;
            }
            return node_cadeia_igual(node_1 -> _link, node_2 ->_link);
        }
    }

    printf("\nNODE ERROR: Não podemos comparar dois termos nulos, bobinho!\n");
    return FALSE;
}

/*
** ----- FUNÇÃO RECURSIVA : node_cadeia_maior -----
** Essa recursão é meio estranha porque ela ocorre ao contrário.
** Primeiro chegamos nos últimos nodes para a partir daí ir subindo
** aos termos anteriores da recursão
**
** TERMO DE RECURSÃO:
**  Se os trechos são iguais. retornamos o termo a termo ANTERIOR
**  da recursão
**
** CASOS BASE:
**  FALSE: Chegamos em nodes em que trecho_1 > trecho_2
**  TRUE: Chegamos em nodes em que trecho_1 < trecho_2
 */
boolean node_cadeia_maior(NODE* node_1, NODE* node_2)
{
    NODE* link_1;
    NODE* link_2;

    if (node_1 != NULL && node_2 != NULL) {

        link_1 = node_1 -> _link;
        link_2 = node_2 -> _link;

        if ( link_1 == NULL && link_2 == NULL ) {
           return node_maior_menor_igual(node_1, node_2);
           // TRUE: trecho_1 > trecho_2; FALSE: trecho_2 > trecho_1, -1: trecho_1 = trecho_2`
        } else {
            if (node_cadeia_maior(link_1,  link_2) != -1) {
                return node_cadeia_maior(link_1, link_2);
            } else {
                return node_maior_menor_igual(node_1, node_2);
            }
        }

    }
    printf("\nNODE ERROR: Não podemos comparar dois termos nulos, bobinho!\n");
    return FALSE;
}



boolean node_print(NODE *node)
{

    if (node != NULL) {
        node_print(node -> _link);
        coloca_os_zeros_a_esquerda(node);
        printf("%d", node -> _trecho);
    }
    return TRUE;
}

// Argumentávelmente, eu fui longe demais para que NODE_SIZE fosse configurável
// Na prática vai ser 4 sempre
boolean coloca_os_zeros_a_esquerda(NODE* node)
{
    int trecho = node -> _trecho;

    if (node -> _link == NULL)
        return FALSE;

    if (1 < NODE_SIZE && trecho < 10 ) {
            print_n_times("0", NODE_SIZE-1);
        }
    else if (2 < NODE_SIZE && (10 <= trecho && trecho < 100) ) {
            print_n_times("0", NODE_SIZE - 2);
        }
    else if (3 < NODE_SIZE && (100 <= trecho && trecho < 1000) ) {
            print_n_times("0", NODE_SIZE - 3);
        }
    return TRUE;
}

int node_atribui_trecho_resultado(NODE* node_1, NODE* node_2, NODE* nodeResultado, boolean hasDifferentSigns){
    if (node_1 == NULL && node_2 != NULL) {

        if(!hasDifferentSigns){
            return node_2 -> _trecho
                + nodeResultado -> _trecho;
        } else {
            return  abs(node_2 -> _trecho);
        }

    } else if (node_1 != NULL && node_2 == NULL) {

        if (!hasDifferentSigns){
            return node_1 -> _trecho
                + nodeResultado -> _trecho;
        } else {
            return abs(node_1 -> _trecho);
        }

    } else {

        if (!hasDifferentSigns) {
            return node_1 -> _trecho + node_2 -> _trecho
                + nodeResultado -> _trecho;
        } else {
            return abs(node_1 -> _trecho - node_2 -> _trecho);
        }
    }
}
