#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    unsigned short i = 8, j = 9, k;
    printf("%d\n", i >> 1 + j >> 1); // 0

    i = 1;
    printf("%d\n", i & ~i); // 0

    i = 2, j = 1, k = 0;
    printf("%d\n", ~i & j ^ k); // 1

    i = 7, j = 8, k = 9;
    printf("%d\n", i ^ j & k); // 15

    exit(EXIT_SUCCESS);
}
