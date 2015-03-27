#include <stdio.h>
#include <stdlib.h>

double inner_product(const double *a, const double *b, int n)
{
    double result = 0.0;
    while(n--)
        result += *a++ * *b++;
    return result;
}

int main()
{
    double a[5] = {1, 2, 3, 4, 5};
    double b[5] = {6, 7, 8, 9, 0};

    printf("Inner product: %lf\n", inner_product(a, b, 5));

    exit(EXIT_SUCCESS);
}
