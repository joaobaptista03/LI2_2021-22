/**
 * @file conversions.h
 * 
 * Este ficheiro contém as assinaturas das funções de operações relacionadas com conversões de tipos.
 * 
 */

#ifndef CONVERTIONS_H
#define CONVERTIONS_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 * A operação i transforma um valor em Long Int.
 * 
 */
bool i_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 * A operação f transforma um valor em Double.
 * 
 */
bool f_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 * A operação c transforma um valor em Char.
 * 
 */
bool c_command (STACK *s, char *token);

/**
 *
 * Este é o header da função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 * A operação s transforma um valor em String.
 * 
 */
bool s_command (STACK *s, char *token);

/**
 *
 * String que irá ser útil para guardar elementos.
 * 
 */
char elem[30];

#endif