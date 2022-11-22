#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_numbers.h"
#include "nodes.h"

int main()
{
    BIGNUMBER *bigNumber_1;
    BIGNUMBER *bigNumber_2;
    BIGNUMBER *bigNumberResultado;
    // char* resenha;
    // resenha = (char *) malloc(100*sizeof(char));
    bigNumber_1 = bignumber_criar();
    bigNumber_2 = bignumber_criar();
    // node_print(node_1);
    // int numeroTamanho = strlen("12345678");
    bignumber_add_numero(bigNumber_1, "-120");
    bignumber_add_numero(bigNumber_2, "-5000");
    bigNumberResultado = bignumber_adicao(bigNumber_2, bigNumber_1);
    bignumber_print(bigNumberResultado);
    print_boolean(bignumber_maior_que(bigNumber_1, bigNumber_2));
    bignumber_apagar(&bigNumber_1);
    bignumber_apagar(&bigNumber_2);
    bignumber_apagar(&bigNumberResultado);
    // slice("12345678", resenha, 4, 8);
    // node_add_trecho(node_1, atoi(resenha));
    // node_add_trecho(node_2, atoi(resenha));
    // node_add_link(node_1, node_2);
    // node_print(node_1);
    // bignumber_add(bigNumber_1, bigNumber_2);
}
