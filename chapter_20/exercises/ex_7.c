#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

unsigned short rotate_left(unsigned short i, int n)
{
    unsigned short shifted = i >> sizeof(unsigned short) * 8 - n;
    return (i << n) | shifted;
}

unsigned short rotate_right(unsigned short i, int n)
{
    while(n--) {
        unsigned short shifted = i & 1;
        i >>= 1;
        i |= shifted << sizeof(unsigned short) * 8 - 1;
    }
    return i;
}

int main()
{
    unsigned short i = 0x1234;
    printf("Original number: %hX\n", i);
    printf("Rotated left 4 bits: %hX\n", rotate_left(i, 4));
    printf("Rotated right 4 bits: %hX\n", rotate_right(i, 4));
    printf("Rotated left 2 bits: %hX\n", rotate_left(i, 2));
    printf("Rotated right 2 bits: %hX\n", rotate_right(i, 2));

    exit(EXIT_SUCCESS);
}
