/**
 * @file math_operations.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com operações matemáticas.
 * 
 */

#include "math_operations.h"

#include <stdio.h>
#include <math.h>
#include <string.h>

/**
 *
 * Esta é a função que executa a operação +, dada a stack e caso o token seja "+".
 * 
 * A operação + dá pop aos 2 elementos do topo da stack e dá push à soma dos dois.
 * 
 */
bool add (STACK *s, char *token) {
    if (strcmp(token, "+") == 0) {
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        TYPE type1 = dx.type;
        TYPE type2 = dy.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type2 == LONG) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.LONG;
        }

        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }
        if (type2 == CHAR) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.CHAR;
        }

        if (dx.type == DOUBLE && dy.type == DOUBLE) {
            pop(s);
            pop(s);

            if (type1 == DOUBLE || type2 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dy.elem.DOUBLE + dx.elem.DOUBLE;
            }
            else {
                d.type = LONG;
                d.elem.LONG = dy.elem.DOUBLE + dx.elem.DOUBLE;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação -, dada a stack e caso o token seja "-".
 * 
 * A operação - dá pop aos 2 elementos do topo da stack e dá push à subtração do segundo pelo do topo.
 * 
 */
bool sub (STACK *s, char *token) {
    if (strcmp(token, "-") == 0) {
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        TYPE type1 = dx.type;
        TYPE type2 = dy.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type2 == LONG) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.LONG;
        }

        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }
        if (type2 == CHAR) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.CHAR;
        }

        if (dx.type == DOUBLE && dy.type == DOUBLE) {
            pop(s);
            pop(s);

            if (type1 == DOUBLE || type2 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dy.elem.DOUBLE - dx.elem.DOUBLE;
            }
            else {
                d.type = LONG;
                d.elem.LONG = dy.elem.DOUBLE - dx.elem.DOUBLE;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação *, dada a stack e caso o token seja "*".
 * 
 * A operação * dá pop aos 2 elementos do topo da stack e dá push ao produto dos dois.
 * 
 */
bool mult (STACK *s, char *token) {
    if (strcmp(token, "*") == 0) {
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        TYPE type1 = dx.type;
        TYPE type2 = dy.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type2 == LONG) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.LONG;
        }

        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }
        if (type2 == CHAR) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.CHAR;
        }

        if (dx.type == DOUBLE && dy.type == DOUBLE) {
            pop(s);
            pop(s);

            if (type1 == DOUBLE || type2 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dy.elem.DOUBLE * dx.elem.DOUBLE;
            }
            else {
                d.type = LONG;
                d.elem.LONG = dy.elem.DOUBLE * dx.elem.DOUBLE;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação /, dada a stack e caso o token seja "/".
 * 
 * A operação / dá pop aos 2 elementos do topo da stack e dá push ao quociente do segundo pelo do topo.
 * 
 */
bool divi (STACK *s, char *token) {
    if (strcmp(token, "/") == 0) {
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        TYPE type1 = dx.type;
        TYPE type2 = dy.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type2 == LONG) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.LONG;
        }

        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }
        if (type2 == CHAR) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.CHAR;
        }

        if (dx.type == DOUBLE && dy.type == DOUBLE) {
            pop(s);
            pop(s);

            if (type1 == DOUBLE || type2 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dy.elem.DOUBLE / dx.elem.DOUBLE;
            }
            else {
                d.type = LONG;
                d.elem.LONG = dy.elem.DOUBLE / dx.elem.DOUBLE;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação (, dada a stack e caso o token seja "(".
 * 
 * A operação ( dá pop ao elemento do topo da stack e dá push ao próprio somado 1.
 * 
 */
bool dec (STACK *s, char *token) {
    if (strcmp(token, "(") == 0) {
        DATA dx = s->stack[s->sp];
        DATA d;

        TYPE type1 = dx.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }

        if (dx.type == DOUBLE) {
            pop(s);

            if (type1 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dx.elem.DOUBLE - 1;
            }
            else if (type1 == LONG) {
                d.type = LONG;
                d.elem.LONG = dx.elem.DOUBLE - 1;
            }
            else {
                d.type = CHAR;
                d.elem.CHAR = dx.elem.DOUBLE - 1;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ), dada a stack e caso o token seja ")".
 * 
 * A operação ) dá pop ao elemento do topo da stack e dá push ao próprio subtraído 1.
 * 
 */
bool inc (STACK *s, char *token) {
    if (strcmp(token, ")") == 0) {
        DATA dx = s->stack[s->sp];
        DATA d;

        TYPE type1 = dx.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }

        if (dx.type == DOUBLE) {
            pop(s);

            if (type1 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = dx.elem.DOUBLE + 1;
            }
            else if (type1 == LONG) {
                d.type = LONG;
                d.elem.LONG = dx.elem.DOUBLE + 1;
            }
            else {
                d.type = CHAR;
                d.elem.CHAR = dx.elem.DOUBLE + 1;
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação %, dada a stack e caso o token seja "%".
 * 
 * A operação % dá pop aos 2 elementos do topo da stack e dá push ao resto da divisão do segundo pelo do topo.
 * 
 */
bool mod (STACK *s, char *token) {
    if (strcmp(token, "%") == 0) {
        char str[30];
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;
        if (dx.type == LONG && dy.type == LONG) {
            sprintf(str, "%ld", dy.elem.LONG % dx.elem.LONG); 
            d = create_data(str, LONG);
            pop(s);
            pop(s);
            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação #, dada a stack e caso o token seja "#".
 * 
 * A operação # dá pop aos 2 elementos do topo da stack e dá push à potência dois dois, sendo que a base é o segundo e o expoente o do topo.
 * 
 */
bool expo (STACK *s, char *token) {
    if (strcmp(token, "#") == 0) {
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        TYPE type1 = dx.type;
        TYPE type2 = dy.type;

        if (type1 == LONG) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.LONG;
        }
        if (type2 == LONG) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.LONG;
        }

        if (type1 == CHAR) {
            dx.type = DOUBLE;
            dx.elem.DOUBLE = dx.elem.CHAR;
        }
        if (type2 == CHAR) {
            dy.type = DOUBLE;
            dy.elem.DOUBLE = dy.elem.CHAR;
        }

        if (dx.type == DOUBLE && dy.type == DOUBLE) {
            pop(s);
            pop(s);

            if (type1 == DOUBLE || type2 == DOUBLE) {
                d.type = DOUBLE;
                d.elem.DOUBLE = pow(dy.elem.DOUBLE, dx.elem.DOUBLE);
            }
            else {
                d.type = LONG;
                d.elem.LONG = pow(dy.elem.DOUBLE, dx.elem.DOUBLE);
            }

            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação &, dada a stack e caso o token seja "&".
 * 
 * A operação & dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "and" entre os dois.
 * 
 */
bool and (STACK *s, char *token) {
    if (strcmp(token, "&") == 0) {
        char str[30];
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        if (dx.type == LONG && dy.type == LONG) {
            sprintf(str, "%ld", dy.elem.LONG & dx.elem.LONG); 
            d = create_data(str, LONG);
            pop(s);
            pop(s);
            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação |, dada a stack e caso o token seja "|".
 * 
 * A operação | dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "or" entre os dois.
 * 
 */
bool or (STACK *s, char *token) {
    if (strcmp(token, "|") == 0) {
        char str[30];
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        if (dx.type == LONG && dy.type == LONG) {
            sprintf(str, "%ld", dy.elem.LONG | dx.elem.LONG); 
            d = create_data(str, LONG);
            pop(s);
            pop(s);
            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ^, dada a stack e caso o token seja "^".
 * 
 * A operação ^ dá pop aos 2 elementos do topo da stack e dá push ao resultado da operação binária "xor" entre os dois.
 * 
 */
bool xor (STACK *s, char *token) {
    if (strcmp(token, "^") == 0) {
        char str[30];
        DATA dx = s->stack[s->sp];
        DATA dy = s->stack[s->sp-1];
        DATA d;

        if (dx.type == LONG && dy.type == LONG) {
            sprintf(str, "%ld", dy.elem.LONG ^ dx.elem.LONG); 
            d = create_data(str, LONG);
            pop(s);
            pop(s);
            push(s,d);
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação ~, dada a stack e caso o token seja "~".
 * 
 * A operação ~ dá pop ao elemento do topo da stack e dá push ao resultado da operação binária "not" do próprio.
 * 
 */
bool not (STACK *s, char *token) {
    if (strcmp(token, "~") == 0) {
        char str[30];
        DATA dx = s->stack[s->sp];
        DATA d;

        if (dx.type == LONG) {
            sprintf(str, "%ld", ~dx.elem.LONG); 
            d = create_data(str, LONG);
            pop(s);
            push(s,d);
            return true;
        }
    }
    return false;
}