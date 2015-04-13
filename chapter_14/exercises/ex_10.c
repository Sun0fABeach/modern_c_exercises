#include <stdio.h>
#include <stdlib.h>

#define ERROR(str, x) fprintf(stderr, str, (double)x)

int main()
{
    ERROR("Range error: index = %g\n", 99);

    exit(EXIT_SUCCESS);
}
