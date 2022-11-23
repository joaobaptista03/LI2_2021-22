/**
 * @file variables.c
 * 
 * Este ficheiro contêm o conteúdo das funções relacionadas com variáveis.
 * 
 */

#include "variables.h"

#include <string.h>

/**
 *
 * Esta é a função que executa a operação <A-Z>, dada a stack e caso o token seja "<A-Z>".
 * 
 */
bool V_commands (STACK *s, char *token) {
    if (strcmp(token, "A") == 0 || strcmp(token, "B") == 0 || strcmp(token, "C") == 0 || strcmp(token, "D") == 0 || strcmp(token, "E") == 0 
     || strcmp(token, "F") == 0 || strcmp(token, "G") == 0 || strcmp(token, "H") == 0 || strcmp(token, "I") == 0 || strcmp(token, "J") == 0
     || strcmp(token, "K") == 0 || strcmp(token, "L") == 0 || strcmp(token, "M") == 0 || strcmp(token, "N") == 0 || strcmp(token, "O") == 0 
     || strcmp(token, "P") == 0 || strcmp(token, "Q") == 0 || strcmp(token, "R") == 0 || strcmp(token, "S") == 0 || strcmp(token, "T") == 0
     || strcmp(token, "U") == 0 || strcmp(token, "V") == 0 || strcmp(token, "W") == 0 || strcmp(token, "X") == 0 || strcmp(token, "Y") == 0 
     || strcmp(token, "Z") == 0) {

        push(s, s->alphabet[token[0] - 65]);

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa as operações :<A-Z>, dada a stack e caso o token seja ":" seguido de uma letra compreendida de A a Z.
 * 
 */
bool SP_command (STACK *s, char *token) {
    if (token[0] == ':') {
        s->alphabet[token[1] - 65] = s->stack[s->sp];
        return true;
    }
    return false;
}