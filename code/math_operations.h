/**
 * @file math_operations.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com operações matemáticas.
 * 
 */

#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 * A operação + dá pop aos 2 elementos do topo da stack e dá push à soma dos dois.
 * 
 */
bool add (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 * A operação - dá pop aos 2 elementos do topo da stack e dá push à subtração do segundo pelo do topo.
 * 
 */
bool sub (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 * A operação * dá pop aos 2 elementos do topo da stack e dá push ao produto dos dois.
 * 
 */
bool mult (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 * A operação / dá pop aos 2 elementos do topo da stack e dá push ao quociente do segundo pelo do topo.
 * 
 */
bool divi (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 * A operação ( dá pop ao elemento do topo da stack e dá push ao próprio somado 1.
 * 
 */
bool dec (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação ), dada a stack e caso o token seja ")".
 * 
 * A operação ) dá pop ao elemento do topo da stack e dá push ao próprio subtraído 1.
 * 
 */
bool inc (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 * A operação % dá pop aos 2 elementos do topo da stack e dá push ao resto da divisão do segundo pelo do topo.
 * 
 */
bool mod (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 * A operação # dá pop aos 2 elementos do topo da stack e dá push à potência dois dois, sendo que a base é o segundo e o expoente o do topo.
 * 
 */
bool expo (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 * A operação & dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "and" entre os dois.
 * 
 */
bool and (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 * A operação | dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "or" entre os dois.
 * 
 */
bool or (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 * A operação ^ dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "xor" entre os dois.
 * 
 */
bool xor (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 * A operação ~ dá pop ao elemento do topo da stack e dá push ao resultado da operação binária "not" do próprio.
 * 
 */
bool not (STACK *s, char *token);

#endif