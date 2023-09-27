#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#include "net.h"

int init_server()
{
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sockfd == -1) {
        perror("Errore nella creazione del socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8069);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind error\n");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Listening on 0.0.0.0:8069\n");

    return sockfd;
}