#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
    while(n--)
        if(*a++ == key)
            return true;
    return false;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    printf("contained: %hhd\n", search(a, 10, 4));
    printf("contained: %hhd\n", search(a, 10, 12));

    exit(EXIT_SUCCESS);
}
