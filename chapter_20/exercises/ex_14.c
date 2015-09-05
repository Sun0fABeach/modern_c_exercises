#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    struct ieee_float {
        unsigned int frac: 23;
        unsigned int exp: 8;
        unsigned int sign: 1;
    } bla = {1, 127, 12345};

    unsigned int *p = &bla;

    printf("%zd\n", sizeof(bla));

    exit(EXIT_SUCCESS);
}
