/**
 * @file stack.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com a STACK.
 * 
 */

#ifndef STACK_H
#define STACK_H

typedef struct stack STACK;

#include <stdbool.h>

/**
 *
 * Este typedef enumera o tipo do elemento:
 * 
 */
typedef enum {
    LONG, /**<Se o tipo do elemento for Long Int*/
    DOUBLE, /**<Se o tipo do elemento for Double*/
    CHAR, /**<Se o tipo do elemento for Char*/ 
    STRING, /**<Se o tipo do elemento for String*/
    ARRAY, /**<Se o tipo do elemento for Array*/
} TYPE ;

/**
 *
 * Este typedef struct corresponde aos elementos da array da STACK:
 * 
 */
typedef struct data {
    TYPE type; /**<Guarda o tipo do elemento*/

    union elem { /**<Union que guarda o elemento dependendo do tipo*/
        long LONG; /**<Guarda o valor em Long Int*/
        double DOUBLE; /**<Guarda o valor em Double*/
        char CHAR; /**<Guarda o valor em Char*/
        char* STRING; /**<Guarda o valor em String*/
        STACK* ARRAY; /**<Guarda o valor em Array*/
    } elem;
} DATA;

/**
 *
 * Esta struct define o que é uma STACK: 
 * 
 */
typedef struct stack {
    DATA *stack; /**<Array de DATA's que guarda os elementos e o tipo deles da stack*/
    int size; //**<Tamanho da array stack*/
    DATA alphabet[26]; /**<Array de DATA's que guarda os elementos e o tipo deles das variáveis A-Z*/
    int sp; /**<Um apontador para o último elmento da stack*/
} STACK;

/**
 *
 * Este é o header da função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack();

/**
 *
 * Este é o header da função que adiciona algo à stack, dado uma stack e um elemento.
 * 
 */
void push(STACK *s, DATA elem);

/**
 *
 * Este é o header da função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
DATA pop (STACK *s);

/**
 *
 * Este é o header da função que decide que tipo tem o input dado, dada uma string.
 * 
 */
TYPE data_selector(char a[]);

/**
 *
 * Este é o header da função que cria a struct data, dada uma string (token).
 * 
 */
DATA create_data (char a[], TYPE t);

/**
 *
 * Este é o header da função que dá print à stack.
 * 
 */
void print_stack (STACK *s, bool a);

#endif