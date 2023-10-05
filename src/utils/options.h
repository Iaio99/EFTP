#pragma once
#ifndef _OPTIONS_H
#define _OPTIONS_H

#include <getopt.h>

static struct option long_options[] = {
	{"port",	optional_argument,	0, 'p'},
	{0,		0,			0, 0}
};


#endif /* _OPTIONS_H */