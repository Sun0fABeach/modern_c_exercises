#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static inline unsigned short swap_bytes(unsigned short i)
{
    return i >> 8 | i << 8 & 0xFF00;
}

int main()
{
    unsigned short i;
    printf("Enter a hexadecimal number: ");
    scanf("%hx", &i);
    printf("Number with bytes swapped: %hX\n", swap_bytes(i));

    exit(EXIT_SUCCESS);
}
