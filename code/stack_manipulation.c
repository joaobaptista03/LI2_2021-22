/**
 * @file stack_manipulation.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com operações de manipulação de stack.
 * 
 */

#include "stack_manipulation.h"

#include <string.h>

/**
 *
 * Esta é a função que executa a operação _, dada a stack e caso o token seja "_".
 * 
 * A operação _ lê o elemento do topo da stack e dá push ao mesmo, duplicando-o.
 * 
 */
bool dup_command(STACK *s, char *token) {
    if (strcmp(token, "_") == 0) {
        DATA d = s->stack[s->sp];
        push(s, d);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ;, dada a stack e caso o token seja ";".
 * 
 * A operação ; retira o elemento do topo da stack.
 * 
 */
bool pop_command (STACK *s, char *token) {
    if (strcmp(token, ";") == 0) {
        pop(s);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação \, dada a stack e caso o token seja "\".
 * 
 * A operação \ dá pop aos 2 elementos do topo da stack e troca-os.
 * 
 */
bool exchange_command (STACK *s, char *token) {
    if (strcmp(token, "\\") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        push(s, x);
        push(s, y);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação @, dada a stack e caso o token seja "@".
 * 
 * A operação @ dá pop aos 3 elementos do topo da stack e dá push ao segundo, depois ao do topo, e depois ao último.
 * 
 */
bool rotate_command (STACK *s, char *token) {
    if (strcmp(token, "@") == 0) {
        DATA x = pop(s);
        DATA y = pop(s);
        DATA z = pop(s);

        push(s, y);
        push(s, x);
        push(s, z);
        return true;
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação $, dada a stack e caso o token seja "$".
 * 
 * A operação $ copia o n-ésimo elemento para o topo da stack.
 * 
 */
bool copy_command (STACK *s, char *token) {
    if (strcmp(token, "$") == 0) {
        int x = pop(s).elem.LONG;
        DATA y = s->stack[s->sp - x];
        push(s, y);
        return true;
    }
    return false;
}