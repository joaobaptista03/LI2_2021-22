/**
 * @file random_funcs.h
 * 
 * Este ficheiro contém as assinaturas das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#ifndef RANDOM_FUNCS_H
#define RANDOM_FUNCS_H

#include <stdbool.h>

/**
 *
 * Este é o header da função que dada uma string, remove todos os 0's no fim, caso seja decimal.
 * 
 */
char* delete_zeros (char *a);

/**
 *
 * Este é o header da função que dada uma string, devolve true caso ela tenha um ponto, caso contrário devolve false.
 * 
 */
bool point(char a[]);

/**
 *
 * Este é o header da função que, dada uma string, calcula quantos tokens 'l' existem nela.
 * 
 */
int count_l(char a[], int N);

/**
 *
 * Este é a função que, dada uma string, remove o primeiro elemento.
 * 
 */
void removefirst (char *a);

/**
 *
 * Este é a função que, dada uma string, devolve o índice do char dado.
 * 
 */
int search(char a[], char b);

#endif