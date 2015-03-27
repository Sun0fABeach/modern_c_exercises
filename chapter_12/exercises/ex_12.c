#include <stdio.h>
#include <stdlib.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    *largest = *second_largest = *a;
    while(--n)
        if(*++a > *largest) {
            *second_largest = *largest;
            *largest = *a;
        } else if(*a > *second_largest)
            *second_largest = *a;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int largest, second_largest;

    find_two_largest(a, 10, &largest, &second_largest);
    printf("Largest: %d, 2nd largest: %d\n", largest, second_largest);

    exit(EXIT_SUCCESS);
}
