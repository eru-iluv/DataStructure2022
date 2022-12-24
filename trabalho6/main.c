#include "arvoreAVL/avl.h"
#include "jogos/jogo.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Abrindo o arquivo, chechando se foi aberto e pulando UTF-8
    FILE *arquivoJogos = fopen("CSV.csv", "r");
    if (arquivoJogos == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO");
        exit(1);
    }
    fseek(arquivoJogos, 3, SEEK_SET);

    char* campo;
    int campoTag = CAMPO_NOME;
    JOGO* jogo;
    char nome[50];
    char produtora[50];
    int ano;
    AVL* avlTree;

    avlTree = avl_criar();


    // Agora preenchemos a arvore com os dados do arquivo
    while (TRUE) {
        campo = read_csv_field(arquivoJogos);

        if (campo == NULL) break;


        if (campoTag == CAMPO_NOME) {
            strcpy(nome, campo);
            jogo = jogo_criar();
            jogo_add_nome(jogo, nome);

        } else if (campoTag == CAMPO_ANO) {
            ano = atoi(campo);
            jogo_add_ano(jogo, ano);

        } else if (campoTag == CAMPO_PRODUTORA) {
            strcpy(produtora, campo);
            avl_insere_jogo(avlTree, jogo);
            campoTag %= 3;

        }

        free(campo);
        campoTag ++;
    }

    fclose(arquivoJogos);


    // por fim, realizamos a exclusão
    int ordem;
    char *ponteiro;

    scanf("%d", &ordem);

    while (TRUE) {

        ponteiro = read_line();

        if (*ponteiro == 'F') break;

        ano = atoi(ponteiro);
        avl_remove_jogo(avlTree, ano);

        free(ponteiro);

    }

    free(ponteiro);

    // por fim, imprimimos a arvore
    if (ordem == 1) {
        avl_preordem(avlTree);
    } else if (ordem == 2) {
        avl_emordem(avlTree);
    } else if (ordem == 3) {
        avl_posordem(avlTree);
    }


    avl_apagar(&avlTree);
    return 0;
}
