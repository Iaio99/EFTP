#pragma once

#include <stdint>
#include "error.h"

#define RRQ 1
#define WRQ 2
#define LRQ 3
#define DATA 4
#define ACK 5
#define ERROR 6

#define DATA_SIZE 1024

typedef opcode_t uint8;
typedef errorcode_t uint16;

struct get_package_t {
        opcode_t op = RRQ;
        char *filename;
}

struct put_package_t {
        opcode_t op = WRQ;
        char *filename;
}

struct list_package_t {
        opcode_t op = LIST;
}

struct data_package_t {
        opcode_t op = DATA;
        int n; //Numero del pacchetto
        char data[DATA_SIZE + 1];
}

struct ack_package_t {
        opcode_t op = ACK;
        int n; //Numero dell'ACK corrispondente al pacchetto ricevuto.
}

struct error_package_t {
        opcode_t op = ERROR;
        error_t error;
}

int init_server(void);