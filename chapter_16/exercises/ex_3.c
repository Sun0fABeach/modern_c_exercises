#include <stdio.h>
#include <stdlib.h>

struct s {
    double real;
    double imaginary;
};

struct s add_complex(struct s s1, struct s s2)
{
    return (struct s){
        .real = s1.real + s2.real, .imaginary = s1.imaginary + s2.imaginary
    };
}

struct s make_complex(double real, double img)
{
    return (struct s){.real = real, .imaginary = img};
}

int main()
{
    struct s c1, c2, c3 = {10.0, 10.0};

    struct s c4 = make_complex(1.0, 2.0);

    printf("%lf, %lf\n", c4.real, c4.imaginary);
    c1 = add_complex(c3, c4);
    printf("%lf, %lf\n", c1.real, c1.imaginary);

    exit(EXIT_SUCCESS);
}
