#include <stdio.h>
#include <stdlib.h>

struct {
    double a;
    union {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} s;

int main()
{
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(s.e));
    printf("%zu\n", sizeof(s.f));
    printf("%zu\n", sizeof(s));

    exit(EXIT_SUCCESS);
}
