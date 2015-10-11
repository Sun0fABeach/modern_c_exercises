#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int count_ones(unsigned char c)
{
    return (c & 1) + ((c & 2) >> 1) + ((c & 4) >> 2) + ((c & 8) >> 3) +
    ((c & 16) >> 4) + ((c & 32) >> 5) + ((c & 64) >> 6) + ((c & 128) >> 7);
}

int main()
{
    printf("Ones in 15: %d\n", count_ones(15));
    printf("Ones in 0: %d\n", count_ones(0));
    printf("Ones in 128: %d\n", count_ones(128));

    exit(EXIT_SUCCESS);
}
