#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "view/user.h"

int main(int argc, char *argv[])
{
        if (argc == 2) {
                fprintf(stderr, "Usage: %s [server ip]\n", argv[0]);
                exit(EXIT_FAILURE);
        }

        int clientfd = socket(AF_INET, SOCK_DGRAM, 0);

        if (clientfd == -1) {
                fprintf(stderr, "Errore nella creazione del socket\n");
                exit(EXIT_FAILURE);
        }

        user_menu();

        close(clientfd);

        return 0;
}