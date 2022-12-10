#include "cliente.h"
#include "binary_tree.h"
#include "utils.h"
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
        binaryTree -> _cliente = NULL;

        return binaryTree;
    }

    return NULL;
}

boolean bt_node_apagar(BT_NODE** binaryTree)
{

    if (*binaryTree != NULL) {
        if ((*binaryTree) -> _galhoDireito != NULL ) {
            bt_node_apagar( &((*binaryTree) -> _galhoDireito) );
        }

        if ((*binaryTree) -> _galhoEsquerdo != NULL) {
            bt_node_apagar( &((*binaryTree) -> _galhoEsquerdo) );
        }

        cliente_apagar(&(*binaryTree) -> _cliente);
        free(*binaryTree);
        *binaryTree = NULL;
        return TRUE;
    }

    return FALSE;
}
void bt_preordem(BT_NODE* binaryTree)
{
    if (binaryTree != NULL) {
        printf("%s\n", cliente_get_cpf(binaryTree -> _cliente));

        bt_preordem(binaryTree -> _galhoEsquerdo);
        bt_preordem(binaryTree -> _galhoDireito);
    }

}

boolean galho_apagar(BT_NODE** binaryTree)
{
    if (*binaryTree != NULL) {
        free(*binaryTree);
        *binaryTree = NULL;
        return TRUE;
    }

    return FALSE;
}



boolean bt_node_insere_cliente(BT_NODE* binaryTree, BT_NODE* arvoreCliente)
{
    char nodeAtualCpf[11];
    char clienteCpf[11];

    if (binaryTree != NULL && binaryTree -> _cliente != NULL && arvoreCliente -> _cliente != NULL) {

        strcpy(nodeAtualCpf, cliente_get_cpf(binaryTree -> _cliente));
        strcpy(clienteCpf,  cliente_get_cpf(arvoreCliente -> _cliente));

        if (cpf_maior(nodeAtualCpf, clienteCpf)) {
            return bt_node_insere_cliente(binaryTree -> _galhoEsquerdo, arvoreCliente);
        } else if (cpf_igual(nodeAtualCpf, clienteCpf)) {
            return FALSE;
        } else {
            return bt_node_insere_cliente(binaryTree -> _galhoDireito, arvoreCliente);
        }
    }

    if (binaryTree == NULL && arvoreCliente != NULL) {
        *binaryTree = *arvoreCliente;
        return TRUE;
    }

    return FALSE;
}


boolean _bt_node_remove_cliente(BT_NODE* binaryTree, char cpf[11])
{
    char nodeAtualCpf[11];
    BT_NODE* galhoEsquerdo;
    BT_NODE* galhoDireito;

    if (binaryTree != NULL && binaryTree -> _cliente != NULL && cpf != NULL) {

        strcpy(nodeAtualCpf, cliente_get_cpf(binaryTree -> _cliente));

        // A ordem pode parecer estranha
        // mas se deve ao fato de cpf_menor basicamente chamar
        // as duas primeiras funções
        if (cpf_maior(nodeAtualCpf, cpf)) {
            return _bt_node_remove_cliente(binaryTree -> _galhoEsquerdo, cpf);

        } else if (cpf_igual(nodeAtualCpf, cpf)) {

            galhoEsquerdo = binaryTree -> _galhoEsquerdo;
            galhoDireito = binaryTree -> _galhoDireito;
            galho_apagar(&binaryTree);

            binaryTree = galhoDireito;
            bt_node_insere_cliente(binaryTree, galhoEsquerdo);

        } else {
            _bt_node_remove_cliente(binaryTree -> _galhoDireito, cpf);
        }
    }
    return FALSE;
}


void _bt_node_busca(BT_NODE* binaryTree, char cpf[11])
{
    CLIENTE* clienteAtual;
    if (binaryTree != NULL && cpf != NULL) {
        clienteAtual = binaryTree -> _cliente ;
        if (cpf_igual( cliente_get_cpf(clienteAtual), cpf) )
        {
            print_cliente(clienteAtual);
        } else if (cpf_maior( cliente_get_cpf(clienteAtual), cpf)) {
            _bt_node_busca(binaryTree -> _galhoDireito, cpf);
        } else {
            _bt_node_busca(binaryTree -> _galhoEsquerdo, cpf);
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
    return bt_node_apagar(&(*binaryTree) -> _raiz);
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
            bt_preordem(binaryTree -> _raiz);
        } else if (binaryTree -> _raiz != NULL && arvoreCliente != NULL) {
            binaryTree ->_raiz = arvoreCliente;
            returnValue = TRUE;
        }
    }

    return returnValue;
}

boolean bt_remove_cliente(BT* binaryTree, char cpf[14])
{
    // boolean returnValue;
    // char* pointerCpfTratado;
    // char cpfTratado[11];

//    pointerCpfTratado = treat_cpf(cpf);
//    strcpy(cpfTratado, pointerCpfTratado);
//    free(pointerCpfTratado);

//    returnValue = _bt_node_remove_cliente(binaryTree -> _raiz, cpf);
    bt_preordem(binaryTree -> _raiz);
    return TRUE;
//    return returnValue;
}
void bt_busca(BT* binaryTree, char cpf[14])
{
    char* pointerCpfTratado;
    char cpfTratado[11];

    pointerCpfTratado = treat_cpf(cpf);
    strcpy(cpfTratado, pointerCpfTratado);
    free(pointerCpfTratado);

    _bt_node_busca(binaryTree -> _raiz, cpf);
}
