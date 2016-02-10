#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char *s = "123asdf", *p;

    int i = strtol(s, &p, 10);
    printf("%d, %s\n", i, p);
    long l = strtol(s, &p, 10);
    printf("%ld, %s\n", l, p);
    long long ll = strtoll(s, &p, 10);
    printf("%lld, %s\n", ll, p);

	exit(EXIT_SUCCESS);
}
