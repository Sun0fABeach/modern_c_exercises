#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned char n = 255;

    while(n) {
        n &= n - 1;
        printf("%hhu\n", n);
    }

    exit(EXIT_SUCCESS);
}
