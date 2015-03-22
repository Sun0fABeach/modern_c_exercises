#include <stdio.h>
#include <stdlib.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    if(n <= 0) return;

    *largest = *second_largest = *a;

    for(int i = 1; i < n; i++) {
        if(a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if(a[i] > *second_largest)
            *second_largest = a[i];
    }
}

int main()
{
    int a[10] = {3,3456,567,-123345, 0, -345, 56, 78, 345, -56};
    int largest, second_largest;

    find_two_largest(a, 10, &largest, &second_largest);
    printf("Largest: %d, second largest: %d\n", largest, second_largest);

    exit(EXIT_SUCCESS);
}
