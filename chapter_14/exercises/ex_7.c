#include <stdio.h>
#include <stdlib.h>

typedef unsigned long ulong;

#define GENERIC_MAX(type) \
    type type##_max(type x, type y) \
    {                         \
        return x > y ? x : y; \
    }                         \

GENERIC_MAX(long)
GENERIC_MAX(ulong)

int main()
{
    printf("%g\n", (double)ulong_max(12, 23));

    exit(EXIT_SUCCESS);
}
