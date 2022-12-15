
#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0
#define boolean int
#define ERRO_GENERICO -4000
#include <stdio.h>

typedef struct Vertice VERTICE;

char *read_line();
void slice(const char *str, char *result, size_t start, size_t end);
int power(int base, int expoente);
boolean starts_with_a_minus(char *str);
void print_boolean(boolean var);
void print_n_times(char *str, int n);
void print_treated_cpf(char cpf[15]);
boolean cpf_igual(char cpf1[15], char cpf2[15]);
boolean cpf_menor(char cpf1[15], char cpf2[15]);
boolean cpf_maior(char cpf1[15], char cpf2[15]);

#endif
