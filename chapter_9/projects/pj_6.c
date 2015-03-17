#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double calc_poly(double x)
{
    return ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6;
}

int main() {
    double x;

    printf("Enter x-value: ");
    scanf("%lf", &x);
    printf("Result of polynomial: %lf\n", calc_poly(x));

    exit(EXIT_SUCCESS);
}
