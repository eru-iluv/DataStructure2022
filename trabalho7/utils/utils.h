#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0
#define boolean int
#define ERRO_GENERICO -4000
#include <stdio.h>

struct VERTICE
{
    int x;
    int y;
};

char *read_line();
void slice(const char *str, char *result, size_t start, size_t end);
int power(int base, int expoente);

boolean starts_with_a_minus(char *str);

void print_boolean(boolean var);
void print_n_times(char *str, int n);

float minf(float a, float b);
int min_vetor_f(float* vetor, int tamanhoVetor);
int max_vetor_f(float* vetor, int tamanhoVetor);
#endif
