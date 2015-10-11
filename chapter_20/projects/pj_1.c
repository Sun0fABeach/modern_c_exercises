#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    union {
        struct ieee_float {
            unsigned int frac: 23;
            unsigned int exp: 8;
            unsigned int sign: 1;
        } float_s;
        float f;
    } float_u = {.float_s = {.sign = 1, .exp = 128, .frac = 0}};

    printf("%f\n", float_u.f);

    exit(EXIT_SUCCESS);
}
