#include <stdio.h>
#include <stdlib.h>

int *find_largest(int a[], int n)
{
    if(n <= 0) return NULL;

    int *largest = a;

    for(int *p = a + 1; p < a + n; p++) {
        if(*p > *largest)
            largest = p;
    }

    return largest;
}

int main()
{
    int a[10] = {3,3456,567,-123345, 0, -345, 56, 78, 345, -56};

    printf("Largest: %d\n", *find_largest(a, 10));

    exit(EXIT_SUCCESS);
}
