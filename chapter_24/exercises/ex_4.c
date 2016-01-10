#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#define TRY_MATH_FCN(fn, arg) (try_math_fcn(fn, arg, "Error in call of "#fn))


double try_math_fcn(double fn(double), double arg, const char *error_msg)
{
    errno = 0;
    double val = fn(arg);
    if(errno) {
        perror(error_msg);
        exit(EXIT_FAILURE);
    }
    return val;
}


int main()
{
    printf("Result first call to log2: %lf\n",
            try_math_fcn(log2, 16, "call to log2 failed"));
    printf("Result of first call to sqrt: %lf\n", TRY_MATH_FCN(sqrt, 25));
    printf("Result second call to log2: %lf\n", TRY_MATH_FCN(log2, -1));

    exit(EXIT_SUCCESS);
}
