/**
 * @file stack.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com a stack.
 * 
 */

#include "stack.h"
#include "random_funcs.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 * Esta é a função que cria uma nova stack, dado um tamanho para essa stack.
 * 
 */
STACK *new_stack() {
    STACK *s = (STACK *) calloc(1, sizeof(STACK));
    s->size = 1000;
    s->stack = (DATA *) calloc(s->size, sizeof(DATA));

    /**As seguintes linhas de código estão a criar as DATA's referentes às variáveis A-Z**/
    s->alphabet[0] = create_data("10", LONG);
    s->alphabet[1] = create_data("11", LONG);
    s->alphabet[2] = create_data("12", LONG);
    s->alphabet[3] = create_data("13", LONG);
    s->alphabet[4] = create_data("14", LONG);
    s->alphabet[5] = create_data("15", LONG);
    s->alphabet[6] = create_data("0", LONG);
    s->alphabet[7] = create_data("0", LONG);
    s->alphabet[8] = create_data("0", LONG);
    s->alphabet[9] = create_data("0", LONG);
    s->alphabet[10] = create_data("0", LONG);
    s->alphabet[11] = create_data("0", LONG);
    s->alphabet[12] = create_data("0", LONG);
    s->alphabet[13] = create_data("\n", CHAR);
    s->alphabet[14] = create_data("0", LONG);
    s->alphabet[15] = create_data("0", LONG);
    s->alphabet[16] = create_data("0", LONG);
    s->alphabet[17] = create_data("0", LONG);
    s->alphabet[18] = create_data(" ", CHAR);
    s->alphabet[19] = create_data("0", LONG);
    s->alphabet[20] = create_data("0", LONG);
    s->alphabet[21] = create_data("0", LONG);
    s->alphabet[22] = create_data("0", LONG);
    s->alphabet[23] = create_data("0", LONG);
    s->alphabet[24] = create_data("1", LONG);
    s->alphabet[25] = create_data("2", LONG);

    s->sp = -1;
    return s;
}

/**
 *
 * Este é a função que adiciona algo à stack, dado uma stack e um elemento.
 * 
 */
void push(STACK *s, DATA elem) {
    (s->sp)++;
    s->stack[s->sp] = elem;
}

/**
 *
 * Este é a função que retira o último elemnto adicionado à stack, dada a própria stack.
 * 
 */
DATA pop (STACK *s) {
    DATA d = (s->stack[s->sp]);
    s->sp--;
    return d;
}

/**
 *
 * Esta é a função que decide que tipo tem o input dado, dada uma string.
 * 
 */
TYPE data_selector(char a[]) {
    if (strcmp(a,"0") == 0) return LONG;
    if (strcmp(a,"0.0") == 0) return DOUBLE;
    char *p;
    if (strtod(a, &p) != 0) {
        if (point(a)) return DOUBLE;
        return LONG;
    }
    if (strtol(a, &p, 10) != 0) return LONG;
    if (strlen(a) == 1) return CHAR;
    return STRING;
}

/**
 *
 * Esta é a função que cria a struct data, dada uma string (token).
 * 
 */
DATA create_data (char *a, TYPE t) {
    char *p;
    DATA d;
    
    if (t == LONG) { 
        d.type = LONG;
        d.elem.LONG = strtol(a, &p, 10);
    }

    if (t == DOUBLE) { 
        d.type = DOUBLE;
        d.elem.DOUBLE = strtod(a, &p);
    }

    if (t == CHAR) { 
        d.type = CHAR;
        d.elem.CHAR = a[0];
    }

    if (t == STRING) { 
        d.type = STRING;
        d.elem.STRING = strdup(a);
    }
    if (t == ARRAY) { 
        d.type = ARRAY;
        d.elem.ARRAY = new_stack();
    }
    
    return d;
}

/**
 *
 * Esta é a função que dá print à stack.
 * 
 */
void print_stack (STACK *s, bool a) {
    for (int i = 0; i <= s->sp; i++) {
        if (s->stack[i].type == LONG) {
            printf("%ld", s->stack[i].elem.LONG);
        }
        if (s->stack[i].type == DOUBLE) {
            char str[30];
            sprintf(str, "%g", s->stack[i].elem.DOUBLE);
            printf("%s", str);
        }
        if (s->stack[i].type == CHAR) {
            printf("%c", s->stack[i].elem.CHAR);
        }
        if (s->stack[i].type == STRING) {
            printf("%s", s->stack[i].elem.STRING);
        }
        if (s->stack[i].type == ARRAY) {
            print_stack(s->stack[i].elem.ARRAY, true);
        }
    }
    if (!a) printf("\n");
}