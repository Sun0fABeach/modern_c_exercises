#include <stdio.h>

int main() {
    unsigned int fib_numbers[40] = {0, 1};

    for(size_t i = 2; i < 40; i++)
        fib_numbers[i] = fib_numbers[i-1] + fib_numbers[i-2];

    for(size_t i = 0; i < 40; i++)
        printf("%u ", fib_numbers[i]);

    putchar('\n');

    return 0;
}
