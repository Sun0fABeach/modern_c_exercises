#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int *low = a+2, *high = a+6;
    int *middle = low + (high - low) / 2;

    printf("middle: %d\n", *middle);

    exit(EXIT_SUCCESS);
}
