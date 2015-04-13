#include <stdio.h>
#include <stdlib.h>

#define NELEMS(a) (sizeof(a) / sizeof(*a))

int main()
{
    int a[10];

    printf("%g\n", (double)NELEMS(a));

    exit(EXIT_SUCCESS);
}
