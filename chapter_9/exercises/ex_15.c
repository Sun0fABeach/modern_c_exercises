#include <stdio.h>
#include <stdlib.h>

double median(double x, double y, double z)
{
    return x < y ? (y < z ? y : z) : (x < z ? x : z);
}

int main()
{
    printf("Median of 4, 2, 9: %g\n", median(4, 2.5, 9.12));

    exit(EXIT_SUCCESS);
}
