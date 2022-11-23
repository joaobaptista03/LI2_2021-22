/**
 * @file input_output.h
 * 
 * Este ficheiro contém as assinaturas das funções de operações relacionadas com input/output.
 * 
 */

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação l, dada a stack e caso o token seja "l".
 * 
 * A operação l lê a linha seguinte dá handle à mesma.
 * 
 */
bool l_command(STACK *s, char *token);

#endif