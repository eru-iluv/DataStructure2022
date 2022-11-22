#include "utils.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

    char* firstChar;

    firstChar = (char*) malloc(2*sizeof(char));
    slice(str, firstChar, 0, 1);

    if (!strcmp(firstChar, "-"))
    {
        free(firstChar);
        return TRUE;
    }
    free(firstChar);
    return FALSE;
}

void print_boolean(boolean var)
{
    if (var) {
        printf("\nTRUE");
    }
    else {
        printf("\nFALSE");
    }
}

void print_n_times(char *str, int N)
{
    for (int i = 0; i < N; i++){
        printf("%s", str);
    }
}
