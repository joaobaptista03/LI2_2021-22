/**
 * @file conversions.c
 * 
 * Este ficheiro contém o conteúdo das funções de operações relacionadas com conversões de tipos.
 * 
 */

#include "conversions.h"

#include <stdio.h>
#include <string.h>

/**
 *
 * Esta é a função que executa a operação i, dada a stack e caso o token seja "i".
 * 
 * A operação i transforma um valor em Long Int.
 * 
 */
bool i_command (STACK *s, char *token) {
    if (strcmp(token, "i") == 0) {
        TYPE type = s->stack[s->sp].type;

        s->stack[s->sp].type = LONG;
        if (type == DOUBLE) s->stack[s->sp].elem.LONG = s->stack[s->sp].elem.DOUBLE;
        if (type == CHAR) s->stack[s->sp].elem.LONG = s->stack[s->sp].elem.CHAR;

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação f, dada a stack e caso o token seja "f".
 * 
 * A operação f transforma um valor em Double.
 * 
 */
bool f_command (STACK *s, char *token) {
    if (strcmp(token, "f") == 0) {
        TYPE type = s->stack[s->sp].type;

        s->stack[s->sp].type = DOUBLE;
        if (type == LONG) s->stack[s->sp].elem.DOUBLE = s->stack[s->sp].elem.LONG;
        if (type == CHAR) s->stack[s->sp].elem.DOUBLE = s->stack[s->sp].elem.CHAR;

        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação c, dada a stack e caso o token seja "c".
 * 
 * A operação c transforma um valor em Char.
 * 
 */
bool c_command (STACK *s, char *token) {
    if (strcmp(token, "c") == 0) {
        int x = pop(s).elem.LONG;
        char elem2[2] = {x, '\0'};
        push(s, create_data(elem2, CHAR));
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação s, dada a stack e caso o token seja "s".
 * 
 * A operação s transforma um valor em String.
 * 
 */
bool s_command (STACK *s, char *token) {
    if (strcmp(token, "s") == 0) {
        TYPE type = s->stack[s->sp].type;
        if (type == LONG) {
            long int x = pop(s).elem.LONG;
            sprintf(elem, "%ld", x);
            push(s, create_data(elem, STRING));
        }
        if (type == DOUBLE) {
            double x = pop(s).elem.DOUBLE;
            sprintf(elem, "%g", x);
            push(s, create_data(elem, STRING));
        }
        if (type == CHAR) {
            char x = pop(s).elem.CHAR;
            char str[2];
            str[0] = x;
            str[1] = '\0';
            push(s, create_data(str, STRING));
        }
        return true;
    }
    return false;
}