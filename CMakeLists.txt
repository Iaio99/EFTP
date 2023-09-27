cmake_minimum_required(VERSION 3.13)
project(TFTP C)

set(CMAKE_C_STANDARD 11)
list(APPEND CMAKE_MODULE_PATH "$(CMAKE_CURRENT_SOURCE_DIR)")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(server.elf
        src/server.c
        src/controller/operations.c
        src/controller/operations.h
	src/model/error.h
        src/model/packages.h
        src/utils/net.c
        src/utils/net.h
)

add_executable(client.elf 
        src/client.c
        src/controller/operations.c
        src/controller/operations.h
	src/model/error.h
        src/model/packages.h
        src/utils/net.c
        src/utils/net.h
        src/view/view.c
)

add_compile_options(PRIVATE -Wall -Wextra -Wpedantic -Werror -O2)
