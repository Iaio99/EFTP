#include <stdbool.h>
#include <regex.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "validation.h"


regex_t regex_port;
regex_t regex_ip_address;


static void print_regerror(int errcode, size_t length, regex_t *compiled)
{
	char buffer[length];
	(void) regerror(errcode, compiled, buffer, length);
	fprintf(stderr, "Regex match failed: %s\n", buffer);
}


bool init_validation(void)
{
	int ret1;
	int ret2;

	ret1 = regcomp(&regex_port, "^((6553[0-5])|(655[0-2][0-9])|(65[0-4][0-9]{2})|(6[0-4][0-9]{3})|([1-5][0-9]{4})|([0-5]{0,5})|([0-9]{1,4}))$", REG_EXTENDED);
	if(ret1) {
		if(ret1 == REG_ESPACE) {
			fprintf(stderr, "%s\n", strerror(ENOMEM));
		} else {
			fprintf(stderr, "Fatal error while setting up port validation regex.\n");
		}
	}
/*
	ret2 = regcomp(&regex_ip_address, "^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$", REG_EXTENDED);
	if(ret2) {
		if(ret2 == REG_ESPACE) {
			fprintf(stderr, "%s\n", strerror(ENOMEM));
		} else {
			fprintf(stderr, "Fatal error while setting up IPv4 address validation regex.\n");
		}
	}
*/
	ret2 = 0;
	return ret1 == 0 && ret2 == 0;
}


void fini_validation(void)
{
	regfree(&regex_port);
	regfree(&regex_ip_address);
}


bool validate_ip_address(char *str)
{
	int ret = regexec(&regex_ip_address, str, 0, NULL, REG_NOTEOL);

	if(ret != 0 && ret != REG_NOMATCH) {
		size_t length = regerror(ret, &regex_ip_address, NULL, 0);
		print_regerror(ret, length, &regex_ip_address);
		return false;
	}
	return ret == 0;
}


bool validate_port(char *str)
{
	int ret = regexec(&regex_port, str, 0, NULL, 0);

	if(ret != 0 && ret != REG_NOMATCH) {
		size_t length = regerror(ret, &regex_port, NULL, 0);
		print_regerror(ret, length, &regex_port);
		return false;
	}
	return ret == 0;
}
