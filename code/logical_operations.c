/**
 * @file logical_operations.c
 * 
 * Este ficheiro contém o conteúdo das funções relacionadas com operações lógicas.
 * 
 */

#include "logical_operations.h"

#include <string.h>
#include <stdio.h>


/**
 *
 * Esta é a função que executa a operação ?, dada a stack e caso o token seja "?".
 * 
 * A operação ? dá pop aos 3 elementos do topo da stack e, se o último for verdade, dá push ao segundo, caso contrário 
 * dá push ao primeiro (topo).
 * 
 */
bool if_command (STACK *s, char *token) {
    if (strcmp(token, "?") == 0) {
        DATA top = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];
        DATA top3 = s->stack[s->sp-2];

        bool b = false;

        if (top3.type == LONG || top3.type == DOUBLE || top3.type == CHAR) {
            if (top3.type == LONG) b = top3.elem.LONG;
            if (top3.type == DOUBLE) b = top3.elem.DOUBLE;
            if (top3.type == CHAR) b = top3.elem.CHAR;

            pop(s);
            pop(s);
            pop(s);

            if (b) push(s, top2);
            else push(s, top);

        return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e>, dada a stack e caso o token seja "e>".
 * 
 * A operação e> dá pop aos 2 elementos do topo da stack e dá push do maior.
 * 
 */
bool higher2_command (STACK *s, char *token) {
    if (strcmp(token, "e>") == 0) {
        DATA top1 = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        TYPE type = top1.type; 
        TYPE type2 = top2.type; 

        if (type == LONG) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.LONG;
        }
        if (type2 == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }
        if (type == CHAR) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.CHAR;
        }
        if (type2 == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }

        if (top1.type == DOUBLE && top2.type == DOUBLE) {
            pop(s);
            pop(s);
            if (type == CHAR) top1.type = CHAR;
            if (type2 == CHAR) top2.type = CHAR;
            if (top1.elem.DOUBLE > top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
            return true;
        }
        if (top1.type == STRING && top2.type == STRING) {
            pop(s);
            pop(s);

            int cmp = strcmp(top1.elem.STRING, top2.elem.STRING);

            if (cmp >= 0) push(s, top1);
            else push(s, top2);

            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e<, dada a stack e caso o token seja "e<".
 * 
 * A operação e< dá pop aos 2 elementos do topo da stack e dá push do menor.
 * 
 */
bool lower2_command (STACK *s, char *token) {
    if (strcmp(token, "e<") == 0) {
        DATA top1 = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        TYPE type = top1.type; 
        TYPE type2 = top2.type; 

        if (type == LONG) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.LONG;
        }
        if (type2 == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }
        if (type == CHAR) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.CHAR;
        }
        if (type2 == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }

        if (top1.type == DOUBLE && top2.type == DOUBLE) {
            pop(s);
            pop(s);
            if (type == CHAR) top1.type = CHAR;
            if (type2 == CHAR) top2.type = CHAR;
            if (top1.elem.DOUBLE < top2.elem.DOUBLE) push(s,top1);
            else push(s, top2);
            return true;
        }
        if (top1.type == STRING && top2.type == STRING) {
            pop(s);
            pop(s);

            int cmp = strcmp(top1.elem.STRING, top2.elem.STRING);

            if (cmp >= 0) push(s, top2);
            else push(s, top1);

            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e|, dada a stack e caso o token seja "e|".
 * 
 * A operação e| dá pop aos 2 elementos do topo da stack e dá push ao que tiver valor verdadeiro, caso os dois sejam verdade, dá push ao segundo.
 * 
 */
bool or_command (STACK *s, char *token) {
    if (strcmp(token, "e|") == 0) {
        DATA top = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        TYPE type = top.type; 
        TYPE type2 = top2.type; 

        bool b1 = false;
        bool b2 = false;

        if (type == LONG) {
            top.type = DOUBLE;
            top.elem.DOUBLE = top.elem.LONG;
        }

        if (type2 == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }

        if (type == CHAR) {
            top.type = DOUBLE;
            top.elem.DOUBLE = top.elem.CHAR;
        }

        if (type2 == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }
        
        if (top.type == DOUBLE && top2.type == DOUBLE) {
            b1 = top.elem.DOUBLE;
            b2 = top2.elem.DOUBLE;

            pop(s);
            pop(s);

            if (type == LONG) {
                top.type = type;
                top.elem.LONG = top.elem.DOUBLE;
            }
            if (type == CHAR) {
                top2.type = type2;
                top.elem.CHAR = top.elem.DOUBLE;
            }
            
            if (b2) push(s, top2);
            else if (b1) push(s, top);

            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação e&, dada a stack e caso o token seja "e&".
 * 
 * A operação e& dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso um deles ou os dois não tenha valor verdadeiro,
 * ou dá push ao elemento do topo caso sejam os dois verdade.
 * 
 */
bool and_command (STACK *s, char *token) {
    if (strcmp(token, "e&") == 0) {
        DATA top = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        TYPE type = top.type; 
        TYPE type2 = top2.type; 

        bool b1 = false;
        bool b2 = false;

        if (type == LONG) {
            top.type = DOUBLE;
            top.elem.DOUBLE = top.elem.LONG;
        }

        if (type2 == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }

        if (type == CHAR) {
            top.type = DOUBLE;
            top.elem.DOUBLE = top.elem.CHAR;
        }

        if (type2 == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }
        
        if (top.type == DOUBLE && top2.type == DOUBLE) {
            b1 = top.elem.DOUBLE;
            b2 = top2.elem.DOUBLE;

            pop(s);
            pop(s);
            
            if (type == LONG) {
                top.type = type;
                top.elem.LONG = top.elem.DOUBLE;
            }
            if (type == CHAR) {
                top2.type = type2;
                top.elem.CHAR = top.elem.DOUBLE;
            }
            
            if (b1 && b2) push(s, top);
            else push(s, create_data("0", LONG));

            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação >, dada a stack e caso o token seja ">".
 * 
 *  A operação > dá pop aos 2 elementos do topo da stack e dá push a "0" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool higher_command (STACK *s, char *token) {
    if (strcmp(token, ">") == 0) {
        DATA top1 = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        if (top1.type == LONG) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.LONG;
        }
        if (top2.type == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }

        if (top1.type == CHAR) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.CHAR;
        }
        if (top2.type == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }

        if (top1.type == DOUBLE && top2.type == DOUBLE) {
            pop(s);
            pop(s);
            if (top1.elem.DOUBLE < top2.elem.DOUBLE) push(s,create_data("1", LONG));
            else push(s, create_data("0", LONG));
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação <, dada a stack e caso o token seja "<".
 * 
 *  A operação < dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja maior que o segundo,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool lower_command (STACK *s, char *token) {
    if (strcmp(token, "<") == 0) {
        DATA top1 = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        if (top1.type == LONG) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.LONG;
        }
        if (top2.type == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }

        if (top1.type == CHAR) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.CHAR;
        }
        if (top2.type == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }

        if (top1.type == DOUBLE && top2.type == DOUBLE) {
            pop(s);
            pop(s);
            if (top1.elem.DOUBLE > top2.elem.DOUBLE) push(s,create_data("1", LONG));
            else push(s, create_data("0", LONG));
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação =, dada a stack e caso o token seja "=".
 * 
 * A operação = dá pop aos 2 elementos do topo da stack e dá push a "1" - Long Int caso os dois elemntos forem iguais,
 * caso contrário dá push a "0" - Long Int.
 * 
 */
bool equal_command (STACK *s, char *token) {
    if (strcmp(token, "=") == 0) {
        DATA top1 = s->stack[s->sp];
        DATA top2 = s->stack[s->sp-1];

        if (top1.type == LONG) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.LONG;
        }
        if (top2.type == LONG) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.LONG;
        }

        if (top1.type == CHAR) {
            top1.type = DOUBLE;
            top1.elem.DOUBLE = top1.elem.CHAR;
        }
        if (top2.type == CHAR) {
            top2.type = DOUBLE;
            top2.elem.DOUBLE = top2.elem.CHAR;
        }

        if (top1.type == DOUBLE && top2.type == DOUBLE) {
            pop(s);
            pop(s);
            if (top1.elem.DOUBLE == top2.elem.DOUBLE) push(s,create_data("1", LONG));
            else push(s, create_data("0", LONG));
            return true;
        }
        if (top1.type == STRING && top2.type == STRING) {
            pop(s);
            pop(s);
            if (top1.elem.STRING[0] != top2.elem.STRING[0]) push(s, create_data("0", LONG));
            else if (strcmp (top1.elem.STRING, top2.elem.STRING) == 0) push(s, create_data("1", LONG));
            else push(s, create_data("0", LONG));
            return true;
        }
    }
    return false;
}

/**
 *
 * Esta é a função que executa a operação !, dada a stack e caso o token seja "!".
 * 
 * A operação ! dá pop ao elemento do topo da stack e dá push a "1" - Long Int caso o elemento do topo seja falso,
 * caso contrário dá push a "1" - Long Int.
 * 
 */
bool no_command (STACK *s, char *token) {
    if (strcmp(token, "!") == 0) {
        DATA top = s->stack[s->sp];
        
        if (top.type == LONG || top.type == DOUBLE || top.type == CHAR) {

            bool b1 = false;

            if (top.type == LONG) b1 = top.elem.LONG;
            if (top.type == DOUBLE) b1 = top.elem.DOUBLE;
            if (top.type == CHAR) b1 = top.elem.CHAR;

            pop(s);
        
            if (b1) push(s, create_data("0", LONG));
            else push(s, create_data("1", LONG));

            return true;
        }
    }
    return false;
}