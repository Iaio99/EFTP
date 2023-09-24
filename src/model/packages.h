#pragma once

#include <stdint>
#include "error.h"

#define RRQ 1
#define WRQ 2
#define LRQ 3
#define DATA 4
#define ACK 5
#define ERROR 6
#define NEGOTIATION 7

#define DATA_SIZE 1466

struct command_package_t {
        uint8_t op;
        char *path;
}

struct data_package_t {
        uint8_t op = DATA;
        int n; //Numero del pacchetto
        char data[DATA_SIZE + 1];
}

struct ack_package_t {
        uint8_t op = ACK;
        int n; //Numero dell'ACK corrispondente al pacchetto ricevuto.
}

struct error_package_t {
        uint8_t op = ERROR;
        error_t error;
}