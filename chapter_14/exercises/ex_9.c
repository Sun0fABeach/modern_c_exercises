#include <stdio.h>
#include <stdlib.h>

#define CHECK(x, y, n) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (n) ? 1 : 0)
#define MEDIAN(x, y, z) ((x) < (y) ? \
        (y) < (z) ? (y) : (z) \
        : (x) < (z) ? (x) : (z))
#define POLYNOMIAL(x) ((((((3*x) + 2)*x - 5)*x - 1)*x + 7)*x - 6)

int main()
{
    printf("%g\n", (double)CHECK(2, 3, 4));
    printf("%g\n", (double)MEDIAN(2, 7, 4));
    printf("%g\n", (double)POLYNOMIAL(2));

    exit(EXIT_SUCCESS);
}
