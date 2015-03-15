#include <stdio.h>
#include <stdlib.h>

int check(int a, int b, int range);

int main()
{
    printf("%d\n", check(2, 4, 8));
    printf("%d\n", check(9, 4, 8));

    exit(EXIT_SUCCESS);
}

int check(int a, int b, int range)
{
    return a >= 0 && a < range && b >= 0 && b < range ? 1 : 0;
}
