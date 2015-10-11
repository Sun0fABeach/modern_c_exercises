#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define TOGGLE_BIT(number, bit_pos) ((number) ^= 1 << (bit_pos))

int main()
{
    int i = 0;
    TOGGLE_BIT(i, 4);
    printf("i: %d\n", i);

    TOGGLE_BIT(i, 4);
    printf("i: %d\n", i);

    exit(EXIT_SUCCESS);
}
