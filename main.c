
#include <stdio.h>
#include <stdlib.h>
#include "lcp.h"

size_t MAX=4000;

int main(int argc, char*argv)
{
	char* prefix=(char*)malloc(MAX);
	char* line=(char*)malloc(MAX);

	if (getline(&prefix, &MAX, stdin) == 0)
	{
		fprintf(stdout, "\n");
		return 0;
	}

	while (getline(&line, &MAX, stdin) > 0)
	{
		lcp_accum(prefix, line);
	}

	fprintf(stdout, "%s\n", prefix);
	return 0;
}


