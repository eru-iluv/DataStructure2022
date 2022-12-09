#include "cliente.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_numbers.h"
#include "binary_tree.h"

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


    }

    scanf("%c", ponteiro);

    if (*ponteiro == 'B'){
        scanf("%s", cpf);
        free(ponteiro);
        bt_busca(binaryTree, cpf);

    } else if (*ponteiro == 'R') {
        scanf("%s", cpf);
        free(ponteiro);
        bt_remove_cliente(binaryTree, cpf);

    } else if (*ponteiro == 'I') {
        free(ponteiro);
        CLIENTE* clienteInserido;

        ponteiro = read_line();
        strcpy(cpf, strtok(ponteiro, ";"));
        nome = strtok(NULL, ";");
        idade = atoi(strtok(NULL, ";"));
        saldo = atof(strtok(NULL, ";"));

        clienteInserido = cliente_criar(cpf, nome, idade, saldo);
        free(ponteiro);

        bt_insere_cliente(binaryTree, clienteInserido);
    }



    return 0;
}
