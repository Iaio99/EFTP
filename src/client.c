#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "view/view.h"

int main(int argc, char *argv[])
{
        if (argc == 2) {
                fprintf(stderr, "Usage: %s [server ip]\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        int clientfd = socket(AF_INET, SOCK_DGRAM, 0);

        if (clientfd == -1) {
                perror("Errore nella creazione del socket\n");
                exit(EXIT_FAILURE);
        }

        /*Connessione con backoff*/

        menu();

        close(clientfd);

        return 0;
}