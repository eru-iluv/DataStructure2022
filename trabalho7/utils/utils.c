#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Vertice
{
    int x;
    int y;
};

boolean vertice_iguais(VERTICE v1, VERTICE v2)
{
    if (v1.x == v2.x && v1.y == v2.y){
        return TRUE;
    }
    return FALSE;
}

char *read_line()
{
    char *string = malloc(sizeof(char));
    char  currentInput;
    int index = 0;

    do{
        currentInput = (char)getchar();
        string = (char*) realloc(string, sizeof(char) * (index+1));
        string[index] = currentInput;
        index++;

        if (currentInput == '\r')
        {
            currentInput = (char)getchar();
        }
    }while((currentInput != '\n') && (currentInput != EOF));

    string[index-1] = '\0';
    return string;
}

// slicing... It slices!!
void slice(const char *str, char *result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
}

// Potenciacao de inteiros (Não é usado nesse código, mas como eu costumo a copiar os utils
// eu decidi manter para usar nos próximos trabalho)
int power(int base, int expoente)
{
    int result = 1;

    for (int i = 1; i <= expoente; i++) {
        result *= base;
    }

    return result;
}

// checa se o string começa com um sinal de menos
boolean starts_with_a_minus(char *str)
{

    if (str[0] == '-')
    {
        return TRUE;
    }
    return FALSE;
}

void print_boolean(boolean var)
{
    if (var) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
}

void print_n_times(char *str, int N)
{
    for (int i = 0; i < N; i++){
        printf("%s", str);
    }
}

void print_treated_cpf(char cpf[15])
{
    char cpfTratado[12] = "00000000000";

    int i = 0;
    int j = 0;
    while (cpf[i] != '\0') {
        if (48 <= cpf[i] && cpf[i] <= 57 ) {
            cpfTratado[j] = cpf[i];
            j++;
        }
        i++;
    }
    printf("%s\n", cpfTratado);
}


boolean cpf_igual(char cpf1[15], char cpf2[15])
{
    if (!strcmp(cpf1, cpf2)) {
        return TRUE;
    }
    return FALSE;
}

boolean _cpf_maior(char cpf1[15], char cpf2[15], int posicao)
{
    if (cpf1[posicao] == '\0') {
        return FALSE;
    } else {
        if (cpf1[posicao] > cpf2[posicao]) {
            return TRUE;
        } else if (cpf1[posicao] == cpf2[posicao]) {
            return _cpf_maior(cpf1, cpf2, posicao + 1);
        } else {
            return FALSE;
        }
    }
}

boolean cpf_maior(char cpf1[15], char cpf2[15])
{
    return _cpf_maior(cpf1, cpf2, 0);
}

boolean cpf_menor(char cpf1[15], char cpf2[15])
{
    return !(cpf_maior(cpf1, cpf2) || cpf_menor(cpf1, cpf2));
}
