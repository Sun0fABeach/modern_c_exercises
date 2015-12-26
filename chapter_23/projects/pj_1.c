#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main()
{
    double a, b, c;

    printf("a: ");
    scanf("%lf", &a);

    printf("b: ");
    scanf("%lf", &b);

    printf("c: ");
    scanf("%lf", &c);

    double probe = pow(2, b) - 4*a*c;

    if(probe < 0) {
        puts("The equation has complex roots!");
        exit(EXIT_SUCCESS);
    }

    printf("x1: %lf\n", (-b + sqrt(probe)) / (2*a));
    printf("x2: %lf\n", (-b - sqrt(probe)) / (2*a));

    exit(EXIT_SUCCESS);
}
