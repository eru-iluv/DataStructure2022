#include "big_numbers.h"
#include "cliente.h"
#include "binary_tree.h"
#include "utils.h"
#include <stdlib.h>


struct BinaryTree
{
    BT* _galhoEsquerdo;
    BT* _galhoDireito;
    CLIENTE* _cliente;
};



BT* bt_criar(CLIENTE* cliente)
{
    BT* binaryTree;
    binaryTree = (BT*) malloc(sizeof(BT));

    if (binaryTree != NULL && cliente != NULL) {
        binaryTree -> _galhoDireito = NULL;
        binaryTree -> _galhoEsquerdo = NULL;
        binaryTree -> _cliente = NULL;

        return binaryTree;
    }

    return NULL;
}

boolean bt_apagar(BT** binaryTree)
{

    if (*binaryTree != NULL) {
        if ((*binaryTree) -> _galhoDireito != NULL ) {
            binarytree_apagar( &((*binaryTree) -> _galhoDireito) );
        }

        if ((*binaryTree) -> _galhoEsquerdo != NULL) {
            binarytree_apagar( &((*binaryTree) -> _galhoEsquerdo) );
        }

        free(*binaryTree);
        *binaryTree = NULL;
        return TRUE;
    }

    return FALSE;
}

boolean galho_apagar(BT** binaryTree)
{
    if (*binaryTree != NULL) {
        free(*binaryTree);
        *binaryTree = NULL;
        return TRUE;
    }

    return FALSE;
}

boolean _binarytree_insere_arvore_cliente(BT* binaryTree, BT* arvoreCliente)
{
    BIGNUMBER* nodeAtualCpf;
    BIGNUMBER* clienteCpf;

    if (binaryTree != NULL && binaryTree -> _cliente != NULL && arvoreCliente -> _cliente != NULL) {

        nodeAtualCpf = cliente_get_cpf(binaryTree -> _cliente);
        clienteCpf =  cliente_get_cpf(arvoreCliente -> _cliente);

        if (bignumber_maior_que(nodeAtualCpf, clienteCpf)) {
            return _binarytree_insere_arvore_cliente(binaryTree -> _galhoEsquerdo, arvoreCliente);
        } else if (bignumber_igual(nodeAtualCpf, clienteCpf)) {
            return FALSE;
        } else {
            return _binarytree_insere_arvore_cliente(binaryTree -> _galhoDireito, arvoreCliente);
        }
    }

    if (binaryTree == NULL && arvoreCliente != NULL) {
        *binaryTree = *arvoreCliente;
        return TRUE;
    }

    return FALSE;
}

boolean _binarytree_remove_cliente(BT* binaryTree, CLIENTE* cliente)
{
    BIGNUMBER* nodeAtualCpf;
    BIGNUMBER* clienteCpf;
    BT* galhoEsquerdo;
    BT* galhoDireito;

    if (binaryTree != NULL && binaryTree -> _cliente != NULL && cliente != NULL) {

        nodeAtualCpf = cliente_get_cpf(binaryTree -> _cliente);

        // A ordem pode parecer estranha
        // mas se deve ao fato de bignumber_menor_que basicamente chamar
        // essas duas funções
        if (bignumber_maior_que(nodeAtualCpf, clienteCpf)) {
            return _binarytree_remove_cliente(binaryTree -> _galhoEsquerdo, cliente);
        } else if (bignumber_igual(nodeAtualCpf, clienteCpf)) {
            galhoEsquerdo = binaryTree -> _galhoEsquerdo;
            galhoDireito = binaryTree -> _galhoDireito;
            galho_apagar(&binaryTree);
            *binaryTree = *galhoDireito;
            _binarytree_insere_arvore_cliente(binaryTree, galhoEsquerdo);
        } else {
            return _binarytree_remove_cliente(binaryTree -> _galhoDireito, cliente);
        }
    }
    return FALSE;
}



CLIENTE* binarytree_busca(BT* binaryTree, BIGNUMBER* cpf)
{
    CLIENTE* nodeAtual;
    if (binaryTree != NULL && cpf != NULL) {
        nodeAtual = binaryTree -> _cliente ;
        if (bignumber_igual( cliente_get_cpf(nodeAtual), cpf) )
        {
            return nodeAtual;
        } else if (bignumber_maior_que( cliente_get_cpf(nodeAtual), cpf)) {
            return binarytree_busca(binaryTree -> _galhoDireito, cpf);
        } else {
            return binarytree_busca(binaryTree -> _galhoEsquerdo, cpf);
        }
    } else {
        return NULL;
    }
}
