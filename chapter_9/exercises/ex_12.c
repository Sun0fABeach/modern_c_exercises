#include <stdio.h>
#include <stdlib.h>

double inner_product(double a[], double b[], int n)
{
    double result = 0;
    for(int i = 0; i < n; i++)
        result += a[i] * b[i];
    return result;
}

int main()
{
    double a[10] = {0,1,2.45,8,-1.376,-4,-5.0923,7,1233.456,0};
    double b[10] = {13.34,1,345,8,-1,-45.0002,-5,7,1,0.189273};

    printf("Inner product: %lf\n", inner_product(a, b, 10));

    exit(EXIT_SUCCESS);
}
