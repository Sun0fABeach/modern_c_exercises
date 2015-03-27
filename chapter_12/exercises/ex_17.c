#include <stdio.h>
#include <stdlib.h>

#define LEN 10

int sum_two_dimensional_array(const int (*a)[LEN], int n)
{
    int sum = 0;
    for(const int *p = *a; p < *(a + n); p++)
        sum += *p;
    return sum;
}

int main()
{
    int a[7][LEN] = {[4] = {[3] = 32}, [6] = {12}};

    printf("Sum: %d\n", sum_two_dimensional_array((const int (*)[LEN])a, 7));

    exit(EXIT_SUCCESS);
}
