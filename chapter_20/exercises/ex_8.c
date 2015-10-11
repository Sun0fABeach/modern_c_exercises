#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

unsigned int f(unsigned int i, int m, int n)
{
    return (i >> (m + 1 - n)) & ~(~0 << n);
}

int main()
{
    printf("i=4, m=3, n=2: %u\n", f(4, 3, 2));
    printf("i=2, m=3, n=4: %u\n", f(2, 3, 4));
    printf("i=1, m=5, n=9: %u\n", f(1, 5, 9));

    exit(EXIT_SUCCESS);
}
