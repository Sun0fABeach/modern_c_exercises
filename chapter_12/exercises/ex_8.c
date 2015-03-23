#include <stdio.h>
#include <stdlib.h>

void store_zeros(int a[], int n)
{
    while(n--)
        *a++ = 0;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    store_zeros(a, 10);
    for(int i = 0; i < 10; i++)
        printf("%d\n", a[i]);

    exit(EXIT_SUCCESS);
}
