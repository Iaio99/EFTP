#include <stdio.h>

#include "utils/net.h"

int main() {
        int server = init_server();
        close(server);

        return 0;
}