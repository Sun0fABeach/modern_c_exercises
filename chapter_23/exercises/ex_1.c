#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


double round_nearest(double num, unsigned short trunc)
{
    double x = pow(10, trunc);
    return (double)((long)(num * x)) / x;
}

int main()
{
    printf("%lf\n", round_nearest(3.14159, 3));
    printf("%lf\n", round_nearest(-3.14159, 3));
    printf("%lf\n", round_nearest(3.14159, 0));
    printf("%lf\n", round_nearest(3.14159, 10));

    exit(EXIT_SUCCESS);
}
