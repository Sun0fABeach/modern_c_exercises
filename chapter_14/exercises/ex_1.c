#include <stdio.h>
#include <stdlib.h>

#define CUBE(x) ((x)*(x))
#define REM4(x) ((x) % 4)
#define STUFF(x, y) ((x)*(y) < 100 ? 1 : 0)

int main()
{
    printf("%g\n", (double)CUBE(3));
    printf("%g\n", (double)REM4(3));
    printf("%g\n", (double)STUFF(3, 30));

    exit(EXIT_SUCCESS);
}
