#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


double evaluate_polynomial(size_t n, double a[n+1], double x)
{
    double res = a[n];

    while(n > 0)
        res = fma(res, x, a[--n]);

    return res;
}

int main()
{
    printf("%lf\n", evaluate_polynomial(2, (double[]){1, 2, 3}, 2));
    printf("%lf\n", evaluate_polynomial(1, (double[]){3, 2}, 3));
    printf("%lf\n", evaluate_polynomial(0, (double[]){3}, 1));

    exit(EXIT_SUCCESS);
}
