#include "cliente/cliente.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree/binary_tree.h"

int main()
{
    char *ponteiro;
    int numeroClientes;
    BT* binaryTree = bt_criar();
    ponteiro = read_line();
    numeroClientes = atoi(ponteiro);
    free(ponteiro);
    char cpf[15];
    char* nome;
    int idade;
    float saldo;

    for (int i = 0; i < numeroClientes; i++) {

        CLIENTE* clienteAtual;
        ponteiro = read_line();


        strcpy(cpf, strtok(ponteiro, ";"));
        nome = strtok(NULL, ";");
        idade = atoi(strtok(NULL, ";"));
        saldo = atof(strtok(NULL, ";"));
        
        clienteAtual = cliente_criar(cpf, nome, idade, saldo);
        bt_insere_cliente(binaryTree, clienteAtual);
        free(ponteiro);

    }
    ponteiro = read_line();

    if (*ponteiro == 'B'){
        scanf("%s", cpf);
        bt_busca(binaryTree, cpf);

    } else if (*ponteiro == 'R') {
        scanf("%s", cpf);;
        bt_remove_cliente(binaryTree, cpf);
        bt_preordem(binaryTree);

    } else if (*ponteiro == 'I') {
        CLIENTE* clienteInserido;
        char* linha = read_line(); 
        // ponteiro = read_line();
        strcpy(cpf, strtok(linha, ";"));
        nome = strtok(NULL, ";");
        idade = atoi(strtok(NULL, ";"));
        saldo = atof(strtok(NULL, ";"));

        clienteInserido = cliente_criar(cpf, nome, idade, saldo);

        bt_insere_cliente(binaryTree, clienteInserido);
        bt_preordem(binaryTree);


        free(linha);
    }

    printf("\n");
    free(ponteiro);
    bt_apagar(&binaryTree);
    return 0;
}
