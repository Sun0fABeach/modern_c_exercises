#include <stdio.h>
#include <stdlib.h>

typedef struct s {
    double real;
    double imaginary;
} Num;

Num add_complex(Num s1, Num s2)
{
    return (Num){
        .real = s1.real + s2.real, .imaginary = s1.imaginary + s2.imaginary
    };
}

Num make_complex(double real, double img)
{
    return (Num){.real = real, .imaginary = img};
}

int main()
{
    Num c1, c2, c3 = {10.0, 10.0};

    Num c4 = make_complex(1.0, 2.0);

    printf("%lf, %lf\n", c4.real, c4.imaginary);
    c1 = add_complex(c3, c4);
    printf("%lf, %lf\n", c1.real, c1.imaginary);

    exit(EXIT_SUCCESS);
}
