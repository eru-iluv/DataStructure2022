#include "binary_tree.h"
#include "../utils/utils.h"
#include "../cliente/cliente.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


struct BinaryTreeNode
{
    BT_NODE* _galhoEsquerdo;
    BT_NODE* _galhoDireito;
    CLIENTE* _cliente;
};

struct BinaryTree
{
    BT_NODE* _raiz;
};

BT_NODE* bt_node_criar(CLIENTE* cliente)
{
    BT_NODE* binaryTree;
    binaryTree = (BT_NODE*) malloc(sizeof(BT_NODE));

    if (binaryTree != NULL && cliente != NULL) {
        binaryTree -> _galhoDireito = NULL;
        binaryTree -> _galhoEsquerdo = NULL;
        binaryTree -> _cliente = cliente;

        return binaryTree;
    }

    return NULL;
}

void bt_node_apagar(BT_NODE** btNode)
{

    if (*btNode != NULL) {

        bt_node_apagar( &((*btNode) -> _galhoDireito) );
        bt_node_apagar( &((*btNode) -> _galhoEsquerdo) );

        cliente_apagar(&(*btNode) -> _cliente);
        free(*btNode);
        *btNode = NULL;

    }

}
void bt_node_preordem(BT_NODE* btNode)
{
    if (btNode != NULL) {
        char cpf[15];
        strcpy(cpf, cliente_get_cpf(btNode -> _cliente));
        print_treated_cpf(cpf);

        bt_node_preordem(btNode -> _galhoEsquerdo);
        bt_node_preordem(btNode -> _galhoDireito);
    }

}

boolean bt_node_insere_cliente(BT_NODE* btNode, BT_NODE* nodeCliente)
{
    char nodeAtualCpf[15];
    char clienteCpf[15];

    if (btNode != NULL && nodeCliente != NULL){
        strcpy(nodeAtualCpf, cliente_get_cpf(btNode -> _cliente));
        strcpy(clienteCpf,  cliente_get_cpf(nodeCliente -> _cliente));

        if (cpf_maior(clienteCpf, nodeAtualCpf)) {
            if (btNode -> _galhoDireito == NULL){
                btNode -> _galhoDireito = nodeCliente;
                return TRUE;
            } else {
                return bt_node_insere_cliente(btNode -> _galhoDireito, nodeCliente);
            }            

        } else if (cpf_igual(nodeAtualCpf, clienteCpf)) {
            return FALSE;

        } else {
            if (btNode -> _galhoEsquerdo == NULL){
                btNode -> _galhoEsquerdo = nodeCliente;
                return TRUE;

            } else {
                return bt_node_insere_cliente(btNode -> _galhoEsquerdo, nodeCliente);
            }            
        }
    }
    
    return FALSE;
}

static void troca_min_direita(BT_NODE* troca, BT_NODE* raiz, BT_NODE* ant)
{
    if (troca ->_galhoEsquerdo != NULL) {
        troca_min_direita(troca -> _galhoEsquerdo, raiz, troca);
        return;
    }
    if (raiz == ant) {
        ant -> _galhoDireito = troca -> _galhoDireito;
    } else {
        ant -> _galhoEsquerdo = troca -> _galhoDireito;
    }
    cliente_apagar(&raiz -> _cliente);
    raiz -> _cliente = troca ->_cliente;
    free(troca);
    troca = NULL;
}

boolean bt_node_remove_cliente(BT_NODE** btNode, char cpf[15])
{
    BT_NODE* nodeRemovido;
    char nodeAtualCpf[15];
    BT_NODE* galhoEsquerdo;
    BT_NODE* galhoDireito;

    if (*btNode == FALSE) {
        return FALSE;
    }

    strcpy(nodeAtualCpf, cliente_get_cpf((*btNode) -> _cliente));
    galhoEsquerdo = (*btNode) -> _galhoEsquerdo;
    galhoDireito = (*btNode) -> _galhoDireito;
    nodeRemovido = *btNode;

    if (cpf_igual(cpf, nodeAtualCpf)) {
        print_cliente(nodeRemovido -> _cliente);
        if (galhoEsquerdo == NULL || galhoDireito == NULL) {

            if (galhoEsquerdo == NULL) {
                *btNode = galhoDireito;
            } else {
                *btNode = galhoEsquerdo;
            }

            free(nodeRemovido);
            nodeRemovido = NULL;
        } else {
            troca_min_direita(nodeRemovido ->_galhoDireito, nodeRemovido, nodeRemovido );
        }
        return TRUE;
    } else if (cpf_maior(cpf, nodeAtualCpf)) {
        bt_node_remove_cliente(&(*btNode) -> _galhoDireito, cpf);
    } else {
        bt_node_remove_cliente(&(*btNode) -> _galhoEsquerdo, cpf);
    }
    return FALSE;
  }


void _bt_node_busca(BT_NODE* btNode, char cpf[15])
{
    CLIENTE* clienteAtual;
    char cpfCliente[15];

    if (btNode != NULL && cpf != NULL) {
        clienteAtual = btNode -> _cliente;
        strcpy(cpfCliente, cliente_get_cpf(clienteAtual));

        if (cpf_igual(cpfCliente, cpf)){
            print_cliente(clienteAtual);

        } else if (cpf_maior(cpf, cpfCliente)) {
            _bt_node_busca(btNode -> _galhoDireito, cpf);
        
        } else {
            _bt_node_busca(btNode -> _galhoEsquerdo, cpf);
        
        }
    } else {
        printf("Pessoa nao encontrada.\n");
    }
}



BT* bt_criar()
{
    BT* binaryTree = (BT*) malloc(sizeof(BT));
    binaryTree -> _raiz = NULL;
    return binaryTree;
}

boolean bt_apagar(BT **binaryTree)
{
    bt_node_apagar(&(*binaryTree) -> _raiz);
    free(*binaryTree);
    *binaryTree = NULL;

    return TRUE;
}


boolean bt_insere_cliente(BT* binaryTree, CLIENTE* cliente)
{
    boolean returnValue;
    BT_NODE* arvoreCliente;

    returnValue = FALSE; // apenas um else estruturado sem condicionais

    if (cliente != NULL) {
        arvoreCliente = bt_node_criar(cliente);
    }
    

    if (binaryTree != NULL) {
        if (binaryTree -> _raiz != NULL){
            returnValue = bt_node_insere_cliente(binaryTree -> _raiz, arvoreCliente);

        } else if (binaryTree -> _raiz == NULL && arvoreCliente != NULL) {

            binaryTree ->_raiz = arvoreCliente;
            returnValue = TRUE;
        }
    }

    return returnValue;
}

void bt_preordem(BT* binaryTree)
{
    printf("Preorder\n");
    bt_node_preordem(binaryTree -> _raiz);
}

boolean bt_remove_cliente(BT* binaryTree, char cpf[15])
{
    boolean returnValue;

    returnValue = bt_node_remove_cliente(&(binaryTree -> _raiz), cpf);

    return returnValue;
}
void bt_busca(BT* binaryTree, char cpf[15])
{
    _bt_node_busca(binaryTree -> _raiz, cpf);
}
