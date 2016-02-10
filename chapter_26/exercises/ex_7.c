#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char *p = "123asdf";
    long value = strtol(p, &p, 10);

    printf("%ld\n", value);
    puts(p);

	exit(EXIT_SUCCESS);
}
