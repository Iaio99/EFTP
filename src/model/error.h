#pragma once

#include <stdint.h>

#define UNDEF 0
#define NOT_FOUND 1
#define NO_SPACE_LEFT 2
#define EXISTS 3

typedef struct error {
        uint8_t err_code;
        char* msg;
}error_t;

const error_t errors[] = {};

void print_error_message(error_t err);