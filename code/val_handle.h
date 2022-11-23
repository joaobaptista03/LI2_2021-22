/**
 * @file val_handle.h
 * 
 * Este ficheiro contém as assinaturas das funções val e handle.
 * 
 */

#ifndef VAL_HANDLE_H
#define VAL_HANDLE_H

#include "stack.h"

#include <stdbool.h>

/**
 *
 * Este é o header da função que é utilizada para colocar os valores na stack, dada a stack e um token diferente de um token de operação.
 * 
 */
bool val (STACK *s, char *token);

/**
 *
 * Este é o header da função que decide que operação executar, dada a stack e um token.
 * 
 */
void handle (STACK *s, char *token);

#endif