#include "catalogo.h"
#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"


void busca_por_ano(CATALOGO *catalogo);
void busca_por_produtora(CATALOGO *catalogo);
boolean is_char(char linha[50]);

int main()
{
    CATALOGO *catalogo = catalogo_criar();
    boolean adicionandoJogos = TRUE;
    boolean buscandoJogos = TRUE;
    while (adicionandoJogos)
    {

      char nome[50], produtora[50];
      int ano;
      char *ponteiro;
      ponteiro = readLine();
      strcpy(nome, ponteiro);
      free(ponteiro);
      if (is_char(nome) && nome[0] == 'F') {
          adicionandoJogos = FALSE;
      } else {
        ponteiro = readLine();
        strcpy(produtora, ponteiro);
        free(ponteiro);
        ponteiro = readLine();
        ano = atoi(ponteiro);
        free(ponteiro);
        JOGO *jogo = jogo_criar();
        jogo_add_ano(jogo, ano);
        jogo_add_nome(jogo, nome);
        jogo_add_produtora(jogo, produtora);
        catalogo_add_jogo(catalogo, jogo);

      }
    }
    while (buscandoJogos) {
      char *ponteiro;
      char comanda[50];
      ponteiro = readLine();
      strcpy(comanda, ponteiro);
      free(ponteiro);
      if (is_char(comanda) && comanda[0] == 'F') {
        buscandoJogos = FALSE;
        catalogo_apagar(&catalogo);
        break;
      } else if (is_char(comanda) && comanda[0] == 'A') {
        busca_por_ano(catalogo);
      } else if (is_char(comanda) && comanda[0] == 'E') {
        busca_por_produtora(catalogo);
      }
    }
    return 0;
}


boolean is_char(char linha[50])
{
    int tamanhoLista = 0;
    char caractereAtual = '/'; // Spaceholder
    while (caractereAtual != '\0') {
        caractereAtual = linha[tamanhoLista];
        tamanhoLista++;
    }
    if (tamanhoLista == 2) {
        return TRUE;
    }
    return FALSE;
}

void busca_por_ano(CATALOGO *catalogo)
{
    int ano;
    scanf("%d", &ano);
    busca_catalogo_por_ano(catalogo, ano);

}

void busca_por_produtora(CATALOGO *catalogo)
{
    char produtora[50];
    strcpy(produtora, readLine());
    busca_catalogo_por_produtora(catalogo, produtora);

}
