#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <setjmp.h>

#include "io.h"

jmp_buf leave_buff;
bool io_initialized;

static void leave(void)
{
	if(io_initialized)
		longjmp(leave_buff, 1);
	else
		exit(EXIT_SUCCESS);
}


char *get_input(char *question, int len, char *buff)
{
	printf("%s", question);

	if(fgets(buff, len, stdin) != NULL) {
		buff[sizeof(buff) - sizeof(char)] = 0;
	} else {
		printf("EOF received, leaving...\n");
		fflush(stdout);
		leave();
	}

	// Empty stdin
	if(strlen(buff) + 1 == len) {
		int ch;
		while(((ch = getchar()) != EOF) && (ch != '\n'));
		if(ch == EOF) {
			printf("EOF received, leaving...\n");
			fflush(stdout);
			leave();
		}
	}

	return buff;
}


bool yes_or_no(char *question, char yes, char no, bool default_answer)
{
	int extra;

	// yes and no characters should be lowercase by default
	yes = (char)tolower(yes);
	no = (char)tolower(no);

	// Which of the two is the default?
	char s;
	char n;
	if(default_answer) {
		s = (char)toupper(yes);
		n = no;
	} else {
		s = yes;
		n = (char)toupper(no);
	}

	while(true) {
		printf("%s [%c/%c]: ", question, s, n);
		extra = 0;

		char c = (char)getchar();
		char ch = 0;
		if(c != '\n') {
			while(((ch = (char)getchar()) != EOF) && (ch != '\n'))
				extra++;
		}
		if(c == EOF || ch == EOF) {
			printf("EOF received, leaving...\n");
			fflush(stdout);
			leave();
		}
		if(extra > 0)
			continue;

		// Check the answer
		if(c == '\n')
			return default_answer;
		else if(c == yes)
			return true;
		else if(c == no)
			return false;
	}
}


char multi_choice(char *question, const char choices[], int num)
{
	char possibilities[2 * num];
	int i;
	int extra;

	for(i = 0; i < num; i++) {
		possibilities[i] = choices[i];
		possibilities[i + 1] = '/';
	}
	possibilities[2 * num - 1] = '\0'; // Remove last '/'

	while(true) {
		printf("%s [%s]: ", question, possibilities);

		extra = 0;
		char c = (char)getchar();
		if(c == '\n')
			continue;
		char ch;
		while(((ch = (char)getchar()) != EOF) && (ch != '\n'))
			extra++;
		if(c == EOF || ch == EOF) {
			printf("EOF received, leaving...\n");
			fflush(stdout);
			leave();
		}
		if(extra > 1) // Need exactly one character on stdin
			continue;

		// Check if the choice is valid
		for(i = 0; i < num; i++) {
			if(c == choices[i])
				return c;
		}
	}
}


void clear_screen(void)
{
	// To whom it may interest: this "magic" is a sequence of escape codes from VT100 terminals:
	// https://www.csie.ntu.edu.tw/~r92094/c++/VT100.html
	printf("\033[2J\033[H");
}

void press_anykey(void)
{
	char c;
	puts("\nPress any key to continue...");
	while((c = (char)getchar()) != '\n');
	(void)c;
}
