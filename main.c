
#include <stdio.h>
#include "lcp.h"

int main(int argc, char*argv)
{
	const char*a=lcp(4, "apple", "apple-basket", "app", "agorist");
	fprintf(stdout, "got: %s\n", a);
}


