/**
 * @file logical_operations.h
 * 
 * Este ficheiro contém a assinatura das funções relacionadas com operações lógicas.
 * 
 */

#ifndef LOGICAL_OPERATIONS_H
#define LOGICAL_OPERATIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Esta é a função que executa a operação ?, dada a stack e caso o token seja "?".
 * 
 * A operação ? dá pop aos 3 elementos do topo da stack e, se o último for verdade, dá push ao segundo, caso contrário 
 * dá push ao primeiro (topo)
 * 
 */
bool if_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação e>, dada a stack e caso o token seja "e>".
 * 
 * A operação e> dá pop aos 2 elementos do topo da stack e dá push do maior.
 * 
 */
bool higher2_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação e<, dada a stack e caso o token seja "e<".
 * 
 * A operação e< dá pop aos 2 elementos do topo da stack e dá push do menor.
 * 
 */
bool lower2_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação e|, dada a stack e caso o token seja "e|".
 * 
 * A operação e| dá pop aos 2 elementos do topo da stack e dá push ao que tiver valor verdadeiro, caso os dois sejam verdade, dá push ao segundo.
 * 
 */
bool or_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação e&, dada a stack e caso o token seja "e&".
 * 
 * A operação e& dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso um deles ou os dois não tenha valor verdadeiro,
 * ou dá push ao elemento do topo caso sejam os dois verdade.
 * 
 */
bool and_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação >, dada a stack e caso o token seja ">".
 * 
 *  A operação > dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool higher_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação <, dada a stack e caso o token seja "<".
 * 
 *  A operação < dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool lower_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação =, dada a stack e caso o token seja "=".
 * 
 * A operação = dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso os dois elemntos forem iguais,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool equal_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação !, dada a stack e caso o token seja "!".
 * 
 * A operação ! dá pop ao elemento do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja falso,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool no_command (STACK *s, char *token);

#endif