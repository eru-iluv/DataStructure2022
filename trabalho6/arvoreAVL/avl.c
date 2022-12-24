#include "avl.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct AvlNode
{
    AVL_NODE* _galhoEsquerdo;
    AVL_NODE* _galhoDireito;
    JOGO* _jogo;
};

struct AvlTree
{
    AVL_NODE* _raiz;
};



static AVL_NODE* avl_node_criar(JOGO* jogo)
{
    AVL_NODE* avlTree;
    avlTree = (AVL_NODE*) malloc(sizeof(AVL_NODE));

    if (avlTree != NULL && jogo != NULL) {
        avlTree -> _galhoDireito = NULL;
        avlTree -> _galhoEsquerdo = NULL;
        avlTree -> _jogo = jogo;
        return avlTree;
    }

    return NULL;
}

static void avl_node_apagar(AVL_NODE** avlNode)
{

    if (*avlNode != NULL) {

        avl_node_apagar( &((*avlNode) -> _galhoDireito) );
        avl_node_apagar( &((*avlNode) -> _galhoEsquerdo) );

        jogo_apagar(&(*avlNode) -> _jogo);
        free(*avlNode);
        *avlNode = NULL;

    }

}




static void avl_node_preordem(AVL_NODE* avlNode)
{
    if (avlNode != NULL) {
        print_jogo(avlNode -> _jogo);
        avl_node_preordem(avlNode -> _galhoEsquerdo);
        avl_node_preordem(avlNode -> _galhoDireito);
    }
}

static void avl_node_emordem(AVL_NODE* avlNode)
{
    if (avlNode != NULL) {
        avl_node_emordem(avlNode -> _galhoEsquerdo);
        print_jogo(avlNode -> _jogo);
        avl_node_emordem(avlNode -> _galhoDireito);
    }
}

static void avl_node_posordem(AVL_NODE* avlNode)
{
    if (avlNode != NULL) {
        avl_node_posordem(avlNode -> _galhoEsquerdo);
        avl_node_posordem(avlNode -> _galhoDireito);
        print_jogo(avlNode -> _jogo);
    }
}




static int avl_node_altura(AVL_NODE* avlNode)
{
    if (avlNode == NULL) return 0;

    int alturaEsquerda;
    int alturaDireita;

    alturaEsquerda = avl_node_altura(avlNode -> _galhoEsquerdo);
    alturaDireita = avl_node_altura(avlNode -> _galhoDireito);

    return maior(alturaEsquerda, alturaDireita) + 1;

}

static int avl_node_bf(AVL_NODE* avlNode)
{
    if (avlNode == NULL) {
        return ERRO_AVL_TREE;
    }

    int alturaEsquerda = avl_node_altura(avlNode -> _galhoEsquerdo);
    int alturaDireita = avl_node_altura(avlNode -> _galhoDireito);

    return alturaDireita - alturaEsquerda;
}



static AVL_NODE* avl_node_rodar_esquerda(AVL_NODE *nodeA)
{
    AVL_NODE* nodeB = nodeA -> _galhoDireito;
    nodeA -> _galhoDireito = nodeB -> _galhoEsquerdo;
    nodeB -> _galhoEsquerdo = nodeA;

    return nodeB;
}

static AVL_NODE* avl_node_rodar_direita(AVL_NODE *nodeA)
{
    AVL_NODE* nodeB = nodeA -> _galhoEsquerdo;
    nodeA -> _galhoEsquerdo = nodeB -> _galhoDireito;
    nodeB -> _galhoDireito = nodeA;

    return nodeB;

}

static AVL_NODE* avl_node_rodar_esquerda_direita(AVL_NODE *avlNode)
{
    avlNode -> _galhoEsquerdo = avl_node_rodar_esquerda(avlNode -> _galhoEsquerdo);
    return avl_node_rodar_direita(avlNode);
}

static AVL_NODE* avl_node_rodar_direita_esquerda(AVL_NODE *avlNode)
{
    avlNode -> _galhoDireito = avl_node_rodar_direita(avlNode->_galhoDireito);
    return avl_node_rodar_esquerda(avlNode);
}



static AVL_NODE* avl_node_rebalance(AVL_NODE** avlNode)
{
    // Eu acho que está faltando algum free aqui ou na remoção
    // Mas eu não consegui achar onde poderia ser

    int fatorBalanceamento = avl_node_bf(*avlNode);

    if (fatorBalanceamento >= 2) {
        if (avl_node_bf((*avlNode) -> _galhoDireito) < 0) {
            *avlNode = avl_node_rodar_direita_esquerda(*avlNode);

        } else {
            *avlNode = avl_node_rodar_esquerda(*avlNode);
        }

    } else if (fatorBalanceamento <= -2){
        if (avl_node_bf((*avlNode) -> _galhoEsquerdo) > 0) {
            *avlNode = avl_node_rodar_esquerda_direita(*avlNode);
        } else {
            *avlNode = avl_node_rodar_direita(*avlNode);
        }

    }
    return *avlNode;
}

static boolean avl_node_insere_jogo(AVL_NODE** nodeAtual, AVL_NODE* nodeInserido)
{
    JOGO* jogoAtual;
    JOGO* jogoInserido;
    boolean inseriu = FALSE;

    if (nodeAtual != NULL && nodeInserido != NULL){
        jogoAtual = (*nodeAtual) -> _jogo;
        jogoInserido = nodeInserido -> _jogo;

        if (jogo_maior(jogoInserido, jogoAtual)) {
            if ((*nodeAtual) -> _galhoDireito == NULL){
                (*nodeAtual) -> _galhoDireito = nodeInserido;
                return TRUE;
            } else {
                inseriu = avl_node_insere_jogo(&(*nodeAtual) -> _galhoDireito, nodeInserido);
            }            

        } else {
            if ((*nodeAtual) -> _galhoEsquerdo == NULL){
                (*nodeAtual) -> _galhoEsquerdo = nodeInserido;
                return TRUE;
            } else {
                inseriu =  avl_node_insere_jogo(&(*nodeAtual) -> _galhoEsquerdo, nodeInserido);
            }
        }
        *nodeAtual = avl_node_rebalance(nodeAtual);
        return inseriu;
    }
    
    return inseriu;
}


static void troca_max_esquerda(AVL_NODE* troca, AVL_NODE* removido, AVL_NODE* ant)
{
    if (troca ->_galhoDireito != NULL) {
        troca_max_esquerda(troca -> _galhoDireito, removido, troca);
        return;
    }

    if (removido == ant) {
        ant -> _galhoEsquerdo = troca -> _galhoEsquerdo;
    } else {
        ant -> _galhoDireito = troca -> _galhoDireito;
    }

    jogo_apagar( &(removido -> _jogo) );

    removido -> _jogo = troca ->_jogo;

    free(troca);
    troca = NULL;
}

static boolean avl_node_remove_jogo(AVL_NODE** avlNode, int ano)
{
    // Ver nota em avl_node_rebalance

    AVL_NODE* nodeRemovido;
    int anoJogoAtual;
    AVL_NODE* galhoEsquerdo;
    AVL_NODE* galhoDireito;
    boolean removeu = FALSE;

    if (*avlNode == NULL) {
        return FALSE;
    }

    anoJogoAtual = jogo_get_ano((*avlNode) -> _jogo);

    galhoEsquerdo = (*avlNode) -> _galhoEsquerdo;
    galhoDireito = (*avlNode) -> _galhoDireito;
    nodeRemovido = *avlNode;

    if (anoJogoAtual == ano) {
        if (galhoEsquerdo == NULL || galhoDireito == NULL) {

            if (galhoEsquerdo == NULL) {
                *avlNode = galhoDireito;
            } else {
                *avlNode = galhoEsquerdo;
            }

            jogo_apagar(&nodeRemovido ->_jogo);
            free(nodeRemovido);
            nodeRemovido = NULL;

        } else {
            troca_max_esquerda(nodeRemovido ->_galhoEsquerdo, nodeRemovido, nodeRemovido);
        }
        return TRUE;

    } else if (ano > anoJogoAtual && (*avlNode) -> _galhoDireito != NULL) {
        removeu = avl_node_remove_jogo(&(*avlNode) -> _galhoDireito, ano);
        *avlNode = avl_node_rebalance(avlNode);
    } else if (ano < anoJogoAtual && (*avlNode) -> _galhoEsquerdo != NULL) {
        removeu = avl_node_remove_jogo(&(*avlNode) -> _galhoEsquerdo, ano);
        *avlNode = avl_node_rebalance(avlNode);
    }

    return removeu;
}



static void avl_node_busca(AVL_NODE* avlNode, int ano)
{
    int anoJogoAtual;

    if (avlNode != NULL) {
        anoJogoAtual = jogo_get_ano(avlNode -> _jogo);

        if (ano == anoJogoAtual){
            print_jogo(avlNode -> _jogo);

        } else if (ano > anoJogoAtual) {
            avl_node_busca(avlNode -> _galhoDireito, anoJogoAtual);

        } else {
            avl_node_busca(avlNode -> _galhoEsquerdo, ano);

        }
    } else {
        printf("JOGO NÃO ENCONTRADO.\n");
    }
}





AVL* avl_criar()
{
    AVL* avlTree = (AVL*) malloc(sizeof(AVL));
    avlTree -> _raiz = NULL;
    return avlTree;
}

boolean avl_apagar(AVL **avlTree)
{
    avl_node_apagar(&(*avlTree) -> _raiz);
    free(*avlTree);
    *avlTree = NULL;

    return TRUE;
}



boolean avl_insere_jogo(AVL* avlTree, JOGO* jogo)
{
    boolean returnValue;
    AVL_NODE* arvoreJogo;

    returnValue = FALSE; // apenas um else estruturado sem condicionais

    if (jogo != NULL) {
        arvoreJogo = avl_node_criar(jogo);
    }
    

    if (avlTree != NULL) {
        if (avlTree -> _raiz != NULL){
            returnValue = avl_node_insere_jogo(&avlTree -> _raiz, arvoreJogo);

        } else if (avlTree -> _raiz == NULL && arvoreJogo != NULL) {

            avlTree ->_raiz = arvoreJogo;
            returnValue = TRUE;
        }
    }

    return returnValue;
}

// FUNÇÃO RECURSIVA
//
// Descrição: a avl continua chamando a remoção,
// até que não hajam jogos daquele ano para serem
// removidos, quando avl_node_remove_jogo retorna
// FALSE
void avl_remove_jogo(AVL* avlTree, int ano)
{
    if (ano < 1) {
        return;
    }

    while(avl_node_remove_jogo(&avlTree ->_raiz, ano));

}

void avl_busca(AVL* avlTree, int ano)
{
   avl_node_busca(avlTree -> _raiz, ano);
}



void avl_preordem(AVL* avlTree)
{
    avl_node_preordem(avlTree -> _raiz);
}

void avl_emordem(AVL* avlTree)
{
    avl_node_emordem(avlTree -> _raiz);
}

void avl_posordem(AVL* avlTree)
{
    avl_node_posordem(avlTree -> _raiz);
}
