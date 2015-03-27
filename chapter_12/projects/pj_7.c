#include <stdio.h>
#include <stdlib.h>

#define N 10

void max_min(int a[], int n, int *max, int *min)
{
    *max = *min = *a;
    for(int *p = a + 1; p < a + n; p++) {
        if(*p > *max)
            *max = *p;
        else if(*p < *min)
            *min = *p;
    }
}

int main()
{
    int b[N], big, small;

    printf("Enter %d numbers: ", N);
    for(int *p = b; p < b + N; p++)
        scanf("%d", p);

    max_min(b, N, &big, &small);

    printf("Largest: %d\n", big);
    printf("Smallest: %d\n", small);

    exit(EXIT_SUCCESS);
}
