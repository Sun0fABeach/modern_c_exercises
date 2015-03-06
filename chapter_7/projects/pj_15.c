#include <stdio.h>
#include <math.h>

int main() {
    long n;
    long double fac = 1.0;

    printf("Enter a positive integer: ");
    scanf("%ld", &n); //max value for long double result: 1754

    printf("Factorial of %ld: ", n);

    while(n >= 2)
        fac *= n--;

    printf("%Lf\n", fac);

    return 0;
}
