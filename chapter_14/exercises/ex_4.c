#include <stdio.h>
#include <stdlib.h>

#define AVG(x, y) (x+y) / 2
#define AREA(x, y) (x) * (y)

int main()
{
    printf("%g\n", (double)10 / AVG(3, 5));
    printf("%g\n", (double)30 / AREA(3, 5));

    #undef AVG
    #undef AREA
    #define AVG(x, y) ((x+y) / 2)
    #define AREA(x, y) ((x) * (y))

    printf("%g\n", (double)10 / AVG(3, 5));
    printf("%g\n", (double)30 / AREA(3, 5));

    exit(EXIT_SUCCESS);
}
