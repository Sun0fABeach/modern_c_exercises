#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i, j, n;
    float x;

    const char *a = "10 20 30\n";
    const char *b = "1.0 2.0 3.0\n";
    const char *c = "0.1 0.2 0.3\n";
    const char *d = ".1 .2 .3\n";

    n = sscanf(a, "%d%f%d", &i, &x, &j); //n=3, i=10, x=20.0, j=30
    printf("n: %d, i: %d, x: %f, j: %d\n", n, i, x, j);
    n = sscanf(b, "%d%f%d", &i, &x, &j); //n=3, i=1, x=0.0, j=2
    printf("n: %d, i: %d, x: %f, j: %d\n", n, i, x, j);
    n = sscanf(c, "%d%f%d", &i, &x, &j); //n=3, i=0, x=0.1, j=0
    printf("n: %d, i: %d, x: %f, j: %d\n", n, i, x, j);
    n = sscanf(d, "%d%f%d", &i, &x, &j); //n=0, i=0, x=0.1, j=0
    printf("n: %d, i: %d, x: %f, j: %d\n", n, i, x, j);

    exit(EXIT_SUCCESS);
}
