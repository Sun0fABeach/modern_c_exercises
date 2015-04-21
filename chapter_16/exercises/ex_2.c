#include <stdio.h>
#include <stdlib.h>

int main()
{
    struct s {
        double real;
        double imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

    c1 = c2;
    c3 = (struct s){
        .real = c1.real + c2.real, .imaginary = c1.imaginary + c2.imaginary
    };

    printf("%lf, %lf\n", c3.real, c3.imaginary);

    exit(EXIT_SUCCESS);
}
