/**
 * @file stack_manipulation.h
 * 
 * Este ficheiro contém as assinaturas das funções relacionadas com operações de manipulação de stack.
 * 
 */

#ifndef STACK_MANIPULATION_H
#define STACK_MANIPULATION_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Esta é a função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 * A operação _ lê o elemento do topo da stack e dá push ao mesmo, duplicando-o.
 * 
 */
bool dup_command(STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 * A operação ; retira o elemento do topo da stack.
 * 
 */
bool pop_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 * A operação \ dá pop aos 2 elementos do topo da stack e troca-os.
 * 
 */
bool exchange_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 * A operação @ dá pop aos 3 elementos do topo da stack e dá push ao segundo, depois ao do topo, e depois ao último.
 * 
 */
bool rotate_command (STACK *s, char *token);

/**
 *
 * Esta é a função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 * A operação $ copia o n-ésimo elemento para o topo da stack.
 * 
 */
bool copy_command (STACK *s, char *token);

#endif