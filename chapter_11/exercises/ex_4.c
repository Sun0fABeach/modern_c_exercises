#include <stdio.h>
#include <stdlib.h>

#define SWAP(a, b) ((a ^= b), (b ^= a), (a ^= b))

void swap(int *p, int *q)
{
    if(*p != *q)
        SWAP(*p, *q);
}

int main()
{
    int a = 1, b = 2;

    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);

    exit(EXIT_SUCCESS);
}
