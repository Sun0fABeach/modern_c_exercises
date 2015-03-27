#include <stdio.h>
#include <stdlib.h>

#define N 10

int main()
{
    int a[N][N];

    for(int *p = *a, *next_one = p; p < *a + N * N; p++)
        if(p == next_one) {
            *p = 1;
            next_one += 11;
        } else {
            *p = 0;
        }

    for(int (*row)[N] = a; row < a + N; row++) {
        for(int *el = *row; el < *row + N; el++)
            printf("%d ", *el);
        putchar('\n');
    }

    exit(EXIT_SUCCESS);
}
