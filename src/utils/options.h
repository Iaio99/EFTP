#pragma once
#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <getopt.h>

static struct option long_options[] = {
	{"port",	required_argument,	0, 'p'},
	{"root",	required_argument,	0, 'r'},
	{"help",	no_argument,		0, 'h'},
	{0,		0,			0, 0}
};


#endif /* _OPTIONS_H */