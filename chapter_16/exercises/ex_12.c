#include <stdio.h>
#include <stdlib.h>

union {
    double a;
    struct {
        char b[4];
        double c;
        int d;
    } e;
    char f[4];
} u;

int main()
{
    printf("%zu\n", sizeof(double));
    printf("%zu\n", sizeof(int));
    printf("%zu\n", sizeof(u.e));
    printf("%zu\n", sizeof(u.f));
    printf("%zu\n", sizeof(u));

    exit(EXIT_SUCCESS);
}
