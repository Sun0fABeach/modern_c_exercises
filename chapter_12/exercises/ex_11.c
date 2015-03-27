#include <stdio.h>
#include <stdlib.h>

int find_largest(int *a, int n)
{
    int max = *a;
    while(--n)
        if(*++a > max)
            max = *a;
    return max;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    printf("Largest: %d\n", find_largest(a, 10));

    exit(EXIT_SUCCESS);
}
