/**
 * @file random_funcs.c
 * 
 * Este ficheiro contém o conteúdo das funções aleatórias que podem ser usadas em vários assuntos.
 * 
 */

#include "random_funcs.h"

#include <string.h>
#include <stdio.h>

/**
 *
 * Esta é a função que dada uma string, remove todos os 0's no fim, caso seja decimal.
 * 
 */
char* delete_zeros (char a[]) {
    bool p = point(a);
    for(int i = strlen(a)-1; i > 0; i--) {
        if (a[i] == '0') a[i] = '\0';
        else if (p && a[i] == '.') {
            a[i+1] = '0';
            return a;
        }
        else return a;
    }
    return 0;
}

/**
 *
 * Esta é a função que dada uma string, devolve true caso ela tenha um ponto, caso contrário devolve false.
 * 
 */
bool point(char a[]) {
    for(unsigned int i = 0; i < strlen(a); i++) {
        if (a[i] == '.') return true;
    }
    return false;
}

/**
 *
 * Este é a função que, dada uma string, calcula quantos tokens 'l' existem nela.
 * 
 */
int count_l(char a[], int N) {
    char linerep[N];
    strcpy(linerep, a);
    char token[BUFSIZ];
    int count = 0;
    while (sscanf (linerep, "%s %[^\n]", token, linerep) == 2) {
        if (strcmp(token, "l") == 0) count++;
    }
    if (strcmp(token, "l") == 0) count++;
    return count;
}

/**
 *
 * Este é a função que, dada uma string, devolve o índice do char dado.
 * 
 */
int search(char a[], char b) {
    for (unsigned int i = 0; i < strlen(a); i++) {
        if (a[i] == b) return i;
    }
    return -1;
}