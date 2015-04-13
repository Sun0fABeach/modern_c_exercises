#include <stdio.h>
#include <stdlib.h>

#define DISP(f, x) printf(#f"(%g) = %g\n", (x), f(x))
#define DISP2(f, x, y) printf(#f"(%g, %g) = %g\n", (x), (y), f(x, y))

double f1(double x)
{
    return 2*x;
}

double f2(double x, double y)
{
    return x * y;
}

int main()
{
    DISP(f1, 3.0);
    DISP2(f2, 3.0, 4.0);

    exit(EXIT_SUCCESS);
}
