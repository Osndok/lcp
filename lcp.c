/*
 * Longest common prefix.
 *
 */

#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "lcp.h"

const char* EMPTY_STRING="";

int firstDifferingCharacter(char*a, char*b)
{
	int i=0;

	while ( *a && *b && *a==*b)
	{
		i++;
		a++;
		b++;
	}

	return i;
}

void lcp_accum(char *prefix, char *next)
{
	int i=firstDifferingCharacter(prefix, next);
	prefix[i]='\0';
}

//BUG: leaks return value
const char* lcp(const int n, ...)
{
	if (n==0)
	{
		return EMPTY_STRING;
	}

	va_list args;
	char* prefix;

	va_start(args, n);
	{
		//NB: The lcp of one string is precisely that string.
		prefix=strdup(va_arg(args, char*));

		//...but can only reduce as we encounter more strings.
		for(int i = 1; *prefix && i < n; i++)
		{
			char* next=va_arg(args, char*);

			int i=firstDifferingCharacter(prefix, next);
			prefix[i]='\0';
		}
	}
	va_end(args);

	return prefix;
}


