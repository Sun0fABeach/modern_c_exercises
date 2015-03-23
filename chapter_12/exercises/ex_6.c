#include <stdio.h>
#include <stdlib.h>

int sum_array(const int *a, int n)
{
    int const *p = a;
    int sum = 0;

    while(p < a + n)
        sum += *p++;

    return sum;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

    printf("sum: %d\n", sum_array(a, 10));

    exit(EXIT_SUCCESS);
}
