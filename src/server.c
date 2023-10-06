#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include "utils/net.h"
#include "utils/options.h"
#include "utils/validation.h"

uint16_t port = 8069;


static bool parse_cmd_line(int argc, char **argv) {
	int c;
//	int option_index;

	while ((c = getopt_long(argc, argv, "r:p:h", long_options, NULL)) != -1) {
		switch (c) {
			case 'h':
				puts("Help\n");
				break;
			case 'r':
				printf("%s\n", optarg);
				break;
			case 'p':
				printf("%s\n", optarg);
				if (validate_port(optarg)) {
					port = (uint16_t)strtoul(optarg, NULL, 10);
				} else {
					perror("Port is not valid\n");
					return false;
				}
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
	if(!init_validation())
                exit(EXIT_FAILURE);

	if(!parse_cmd_line(argc, argv)) {
		exit(EXIT_FAILURE);
	}

        int server = init_server(port);
        pause();
        close(server);

        return 0;
}