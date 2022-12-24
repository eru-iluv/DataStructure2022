#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0
#define boolean int
#define ERRO_UTILS -4000
#define maior(a,b) ((a > b) ? a : b)
#define menor(a,b) ((a < b) ? a : b)

#define CAMPO_NOME 1
#define CAMPO_ANO 2
#define CAMPO_PRODUTORA 3

#include <stdio.h>

struct VERTICE
{
    int x;
    int y;
};

// MUITO ORGULHO DESSE!! 
char *read_csv_field(FILE *stream);
char *read_line();

int power(int base, int expoente);

boolean starts_with_a_minus(char *str);

void print_boolean(boolean var);
void print_n_times(char *str, int n);

boolean str_maior(char* str1, char* str2);
boolean str_menor(char* str1, char* str2);

void slice(const char *str, char *result, size_t start, size_t end);
int min_vetor_f(float* vetor, int tamanhoVetor);
int max_vetor_f(float* vetor, int tamanhoVetor);
#endif
