#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#include "utils/net.h"
#include "utils/options.h"
#include "utils/validation.h"

uint16_t port = 8069;

static void display_usage(char **argv) {
        printf("%s [OPTIONS]\n\n", argv[0]);
	printf("\nADDITIONAL OPTIONS:\n");
        printf("\t-p <port>, --port=<port>: Listening port. If not set, default to %d\n", port);
	printf("\t-r <path>, --root=<path>: Root of the server. If not set, default to ./\n");
	printf("\t-h, Print this message\n");
}

static bool parse_cmd_line(int argc, char **argv) {
	int c;

	while ((c = getopt_long(argc, argv, "hr:p", long_options, NULL)) != -1) {
		switch (c) {
                        case 'h':
                                display_usage(argv);
                                return false;
                                break;
			case 'r':
				printf("%s\n", optarg);
				break;
			case 'p':
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
                                perror("Invalid options\n");
                                return false;
		}
	}

	return true;
}

int main(int argc, char **argv)
{
	if(!init_validation())
                return -1;

	if(!parse_cmd_line(argc, argv)) {
		return -1;
	}

        int server = init_server(port);
        pause();
        close(server);

        return 0;
}