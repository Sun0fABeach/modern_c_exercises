#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

unsigned char reverse_bits(unsigned char n)
{
    int reversed = n & 1;
    for(size_t i = 1; i < sizeof(unsigned char)*8; i++) {
        int bit = n >> i & 1;
        reversed <<= 1;
        reversed |= bit;
    }
    return reversed;
}

int main()
{
    printf("127 reversed: %u\n", reverse_bits(127));
    printf("1 reversed: %u\n", reverse_bits(1));
    printf("129 reversed: %u\n", reverse_bits(129));
    printf("64 reversed: %u\n", reverse_bits(64));

    exit(EXIT_SUCCESS);
}
