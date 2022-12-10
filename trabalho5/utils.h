
#ifndef UTILS_H
#define UTILS_H
#define TRUE 1
#define FALSE 0
#define boolean int
#define ERRO_GENERICO -4000
#include <stdio.h>
char *read_line();
void slice(const char *str, char *result, size_t start, size_t end);
int power(int base, int expoente);
boolean starts_with_a_minus(char *str);
void print_boolean(boolean var);
void print_n_times(char *str, int n);
char* treat_cpf(char cpf[14]);
boolean cpf_igual(char cpf1[11], char cpf2[11]);
boolean cpf_menor(char cpf1[11], char cpf2[11]);
boolean cpf_maior(char cpf1[11], char cpf2[11]);
#endif
