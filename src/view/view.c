#include <stdio.h>

#include "view.h"
#include "../utils/io.h"

int client_menu(void)
{
        char options[4] = {'1', '2', '3', '4'};
        char op;

        clear_screen();

        puts("1. Scaricare un file dal server\n");
        puts("2. Fare l'upload di un file sul server\n");
        puts("3. Fare la lista dei file disponibili sul server\n");
        puts("4. Chiudere la connessione\n");

        op = multi_choice("Quale operazione vuoi eseguire?", options, 4);
	return op - '1';
}