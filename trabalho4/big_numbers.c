#include "big_numbers.h"
#include "nodes.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BigNumber
{
    NODE *_inicio;
    NODE *_end;
    int _size;
    boolean _isNegative;
};

BIGNUMBER *bignumber_criar()
{
    BIGNUMBER *bigNumber;
    bigNumber = (BIGNUMBER *)malloc(sizeof(BIGNUMBER));
    if (bigNumber != NULL)
    {
        bigNumber->_inicio = NULL;
        bigNumber->_end = NULL;
        bigNumber->_size = 0;
        bigNumber->_isNegative = FALSE;
        return bigNumber;
    }
    return NULL;
};

boolean bignumber_apagar(BIGNUMBER **bigNumber)
{
    if (*bigNumber != NULL)
    {
        node_apagar_cadeia(&((*bigNumber)->_inicio));
        free(*bigNumber);
        *bigNumber = NULL;
        return TRUE;
    }
    return FALSE;
}

boolean bignumber_append(BIGNUMBER *bigNumber, int trecho)
{
    NODE *node;
    node = node_criar();
    node_add_trecho(node, trecho);

    if (node != NULL && bigNumber != NULL && trecho >= 0)
    {
        if (bigNumber->_size == 0)
        {
            bigNumber->_inicio = node;
            bigNumber->_end = node;
        }
        else
        {
            node_add_link(bigNumber->_end, node);
            bigNumber->_end = node;
        }

        (bigNumber->_size)++;
    }
    return FALSE;
}

boolean bignumber_add_numero(BIGNUMBER *bigNumber, char *numero)
{
    int numeroTamanho;
    int numeroIteracoes;
    int resto;
    char *trecho = (char *)malloc(NODE_SIZE * sizeof(char));
    char *numeroAbsoluto = (char *)malloc(strlen(numero) * sizeof(char));

    if (bigNumber != NULL)
    {

        if (starts_with_a_minus(numero))
        {
            bigNumber->_isNegative = TRUE;
            slice(numero, numeroAbsoluto, 1, strlen(numero));
        }
        else
        {
            slice(numero, numeroAbsoluto, 0, strlen(numero));
        }

        numeroTamanho = strlen(numeroAbsoluto);
        numeroIteracoes = numeroTamanho / NODE_SIZE;
        resto = numeroTamanho % NODE_SIZE;

        for (int i = numeroIteracoes; i > 0; i--)
        {
            slice(numeroAbsoluto, trecho, (i - 1) * NODE_SIZE + resto,
                  i * NODE_SIZE + resto);
            bignumber_append(bigNumber, atoi(trecho));
        }
        if (resto != 0)
        {
            free(trecho);
            trecho = (char *)malloc(resto * sizeof(char));
            slice(numeroAbsoluto, trecho, 0, resto);
            bignumber_append(bigNumber, atoi(trecho));
        }
        free(trecho);
    }
    return FALSE;
}

BIGNUMBER *bignumber_adicao(BIGNUMBER *bigNumber_1, BIGNUMBER *bigNumber_2)
{
    BIGNUMBER *bigNumberResultado;
    NODE *node_1;
    NODE *node_2;
    boolean maiorQueMaxSize = FALSE;

    if (bigNumber_1 != NULL && bigNumber_2 != NULL)
    {
        bigNumberResultado = bignumber_criar();

        node_1 = bigNumber_1 -> _inicio;
        node_2 = bigNumber_2 -> _inicio;

        while (node_1 != NULL || node_2 != NULL) {
            if (!maiorQueMaxSize) {
                bignumber_append(bigNumberResultado, 0);
            }

            maiorQueMaxSize =
                node_adicao(node_1, node_2, bigNumberResultado -> _end);

            node_1 != NULL ? node_1 = node_get_link(node_1) : 0;
            node_2 != NULL ? node_2 = node_get_link(node_2) : 0;

            if (maiorQueMaxSize) {
                bignumber_append(bigNumberResultado, 1);
            }

        }

        return bigNumberResultado;
    }
    return NULL;
}

boolean bignumber_maior_que(BIGNUMBER *bigNumber_1, BIGNUMBER * bigNumber_2){
     if (bigNumber_1 != NULL && bigNumber_2 != NULL) {

         if ( (bigNumber_1 -> _size) == (bigNumber_2 -> _size) ) {
             return node_cadeia_maior(bigNumber_1 -> _inicio, bigNumber_2 -> _inicio);

         } else if ( (bigNumber_1 -> _size) > (bigNumber_2 -> _size) ) {
             return TRUE;
         }
        return FALSE;
     }

     printf("\nERRO BIGNUMBER: Não podemos comparar um bignumber nulo\n");
     return FALSE;
}

boolean bignumber_igual(BIGNUMBER *bigNumber_1, BIGNUMBER *bigNumber_2){
    if (bigNumber_1 != NULL && bigNumber_2 != NULL) {
        if ( (bigNumber_1 -> _size) == (bigNumber_2 -> _size) ) {
            return node_cadeia_igual(bigNumber_1 -> _inicio,
                                bigNumber_2 -> _inicio);
        }
        return FALSE;
    }

    printf("\nERRO BIGNUMBER: Não podemos comparar um bignumber nulo\n");
    return FALSE;
}

boolean bignumber_menor_que(BIGNUMBER *bigNumber_1, BIGNUMBER * bigNumber_2){

    if (bigNumber_1 != NULL && bigNumber_2 != NULL){
        if (!(bignumber_maior_que(bigNumber_1, bigNumber_2)
               || bignumber_igual(bigNumber_1, bigNumber_2)))
        {
            return TRUE;
        }

        return FALSE;
    }

    printf("\nERRO BIGNUMBER: Não podemos comparar um bignumber nulo\n");
    return FALSE;

}



boolean bignumber_print(BIGNUMBER *bigNumber)
{
    NODE *inicio;
    if (bigNumber != NULL)
    {
        inicio = bigNumber->_inicio;
        bigNumber->_isNegative == TRUE ? printf("-") : 0;
        node_print(inicio);
        return TRUE;
    }
    return FALSE;
}
