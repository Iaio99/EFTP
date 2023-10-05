#include <stdio.h>

#include "view.h"

void menu(void)
{
        int opt;

        while(1) {
                printf("Quale operazione vuoi eseguire?\n");
                printf("1. Scaricare un file\n");
                printf("2. Fare l'upload di un file\n");
                printf("3. Fare la lista dei file disponibili sul server\n");
                printf("4. Chiudi la connessione\n");
                scanf("%d", &opt);

                switch(opt) {
                        case 1:
                                break;
                        case 2:
                                break;
                        case 3:
                                break;
                        case 4:
                                return;
                        default:
                                printf("Opzione non riconosciuta.\n\n\n");
                                break;
                }

        }

        return;
}