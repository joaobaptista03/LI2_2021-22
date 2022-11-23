/**
 * @file input_output.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com input/output.
 * 
 */

#include "input_output.h"
#include "main.h"
#include "val_handle.h"

#include <string.h>

/**
 *
 * Esta é a função que executa a operação l, dada a stack e caso o token seja "l".
 * 
 * A operação l lê a linha seguinte dá handle à mesma.
 * 
 */
bool l_command(STACK *s, char *token) {
    if (strcmp(token, "l") == 0) {
        val(s, reads[l]);
        l++;
        return true;
    }
    return false;
}