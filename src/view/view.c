#include <stdio.h>

#include "view.h"

int client_menu(void)
{
        char options[3] = {'1', '2', '3'};
        char op;

        puts("1. Scaricare un file\n");
        puts("2. Fare l'upload di un file\n");
        puts("3. Fare la lista dei file disponibili sul server\n");
        puts("4. Chiudi la connessione\n");

        op = multi_choice("Quale operazione vuoi eseguire?", options, 3);
	return op - '1';
}