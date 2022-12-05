#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "big_numbers.h"
#include "nodes.h"

int main()
{
    char *ponteiro;
    int numeroComandos;

    ponteiro = read_line();
    numeroComandos = atoi(ponteiro);
    free(ponteiro);


    for (int i = 0; i < numeroComandos; i++) {
       char* operacao;

       BIGNUMBER* bigNumber_1 = bignumber_criar();
       char* numero_1;


       BIGNUMBER* bigNumber_2 = bignumber_criar();
       char* numero_2;

       ponteiro = read_line();


       operacao = strtok(ponteiro, " ");

       numero_1 = strtok(NULL, " ");
       numero_2 = strtok(NULL, " ");

       bignumber_add_numero(bigNumber_1, numero_1);
       bignumber_add_numero(bigNumber_2, numero_2);

       printf("Resultado :: ");

       if (strcmp(operacao, "soma") == 0) {
            bignumber_print(bignumber_adicao(bigNumber_1, bigNumber_2));
        }
       else if(strcmp(operacao, "maior") == 0) {
            print_boolean(bignumber_maior_que(bigNumber_1, bigNumber_2));
       }
       else if (strcmp(operacao, "menor") == 0)
       {
           print_boolean(bignumber_menor_que(bigNumber_1, bigNumber_2));
       }
       else if (strcmp(operacao, "igual") == 0)
       {
           print_boolean(bignumber_igual(bigNumber_1, bigNumber_2));
       }

       bignumber_apagar(&bigNumber_1);
       bignumber_apagar(&bigNumber_2);
    }

    return 0;
}
