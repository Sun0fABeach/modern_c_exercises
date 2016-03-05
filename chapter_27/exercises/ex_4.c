#include <stdlib.h>
#include <stdio.h>
#include <tgmath.h>


int main()
{
    int i;
    float f;
    double d;
    long double ld;
    float complex fc;
    double complex dc;
    long double complex ldc;

    tan(i);
    fabs(f);
    asin(d);
    exp(ld);
    log(fc);
    acosh(dc);
    nexttoward(d, ld);
    remainder(f, i);
    copysign(d, ld);
    carg(i);
    cimag(f);
    conj(ldc);

	exit(EXIT_SUCCESS);
}
