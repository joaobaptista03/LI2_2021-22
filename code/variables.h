/**
 * @file variables.h
 * 
 * Este ficheiro contém a assinatura das funções relacionadas com variáveis.
 * 
 */

#ifndef VARIABLES_H
#define VARIABLES_H

#include "stack.h"

#include <stdbool.h> 

/**
 *
 * Esta é a função que executa a operação <A-Z>, dada a stack e caso o token seja "<A-Z>".
 * 
 */
bool V_commands (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa as operações :<A-Z>, dada a stack e caso o token seja ":" seguido de uma letra compreendida de A a Z.
 * 
 */
bool SP_command (STACK *s, char *token);

#endif