#include <stdio.h>

#if MINE
#include <ft/getopt.h>
#define GETOPT ft_getopt
#define OPTIND ft_optind
#define OPTERR ft_opterr
#define OPTARG ft_optarg
#define OPTOPT ft_optopt
#else
#include <unistd.h>
#include <getopt.h>
#define GETOPT getopt
#define OPTIND optind
#define OPTERR opterr
#define OPTARG optarg
#define OPTOPT optopt
#endif

extern int OPTIND;
extern int OPTERR;
extern int OPTOPT;
extern char* OPTARG;

#ifndef OPTERR_VAL
#define OPTERR_VAL 0
#endif

#ifndef OPTSTRING
#define OPTSTRING ""
#endif

int main(int argc, char **argv)
{
	printf("argc: %i\n", argc);
	OPTERR = OPTERR_VAL;
	int c;
	while ((c = GETOPT(argc, argv, OPTSTRING)) != -1) {
		printf("ret: %x arg: \"%s\"", (unsigned) c, OPTARG);
		if (c == ':' || c == '?')
			printf(" OPTOPT: %x", (unsigned) OPTOPT);
		printf("\n");
		OPTARG = NULL;
		OPTOPT = 0;
	}
	printf("remaining arguments:\n");
	for (; OPTIND < argc; ++OPTIND)
		printf("%i: \"%s\"\n", OPTIND, argv[OPTIND]);
	printf("end\n");
}
