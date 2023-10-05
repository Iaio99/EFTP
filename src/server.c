#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include "utils/net.h"
#include "utils/options.h"

uint16_t port = 8069;

static bool parse_cmd_line(int argc, char **argv) {
	int c;
//	int option_index;

	while ((c = getopt_long(argc, argv, "p:", long_options, NULL)) != -1) {
		switch (c) {
			case 'p':
				port = (uint16_t)strtoul(optarg, NULL, 10);
				break;

			case 0:
			case '?':
			default:
                                break;
		}
	}

	return true;
}

int main(int argc, char **argv)
{
	if(!parse_cmd_line(argc, argv)) {
		exit(EXIT_FAILURE);
	}

        int server = init_server(port);
        pause();
        close(server);

        return 0;
}