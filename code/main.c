/**
 * @file main.c
 * Este ficheiro contém a função main que é a função principal do programa.
 * 
 */

#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include "random_funcs.h"
#include "main.h"
#include "val_handle.h"

/**
 * Esta é a função principal do programa que:
 * 
 * Cria uma nova Stack;
 * Lê uma linha;
 * Executa as operações lidas usando as funções definidas nos outros ficheiros.  
 */
int main() {
    STACK *s = new_stack(); /** <Cria uma stack nova com um espaço para 1000 elementos */

    char token[BUFSIZ]; /** <Array (String) onde vai ser guardado cada token */
    
    assert (fgets (line, BUFSIZ, stdin) != NULL); /** <Linha que lê o primeiro input, guardando na string line */

    char read_temp[30]; /** <String que guarda cada linha lida pelo comando l, sendo apagada depois */
    int cont = count_l(line, strlen(line));

    for (int i = 0; i < cont; i++) { /** <Loop que lê as l linhas */
        assert (fgets (read_temp, 30, stdin) != NULL);
        strcpy(reads[i], read_temp);
        strcpy(token, "\0");
    }

    l = 0;
    while (sscanf (line, "%s %[^\n]", token, line) == 2) { /** <Linha que, para cada token de line, chama a função handle para o mesmo */
    /*
        if (token[0] == '\"' && search(token, '\"') == -1) {
            char trash[BUFSIZ];
            int indline = search(line, '\"');
            memcpy(&token[strlen(token)], line, 4 * (indline + 1));
            sscanf(line, "%[^\"] %c %[^\n]", trash, trash, line);
        }
    */
        handle (s, token);
    }
    handle (s, token);
    print_stack(s, false); /** <Linha que dá print à stack */
    free(s); /** <Linha que desaloca a memória no fim do programa */
    return 0;
}



// Comando gcc (tem de estar na pasta code)
// gcc -Wall -Wextra -pedantic-errors -O2 *.c -lm