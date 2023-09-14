#pragma once

#define UNDEF 0
#define NOT_FOUND 1
#define NO_SPACE_LEFT 2
#define EXISTS 3

typedef struct error {
        opcode_t err_code;
        char* msg;
}error_t;

const error_t errors[] = {};