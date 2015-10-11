#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    return (high_byte << 8) + low_byte;
}

int main()
{
    printf("4f and 73 is %hx\n", create_short(0x4f, 0x73));

    exit(EXIT_SUCCESS);
}
