#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int a1[1000];
    for(int i = 0; i < 1000; ++i)
        a1[i] = 999 - i;

    int a2[10000];
    for(int i = 0; i < 10000; ++i)
        a2[i] = 9999 - i;

    int a3[100000];
    for(int i = 0; i < 100000; ++i)
        a3[i] = 99999 - i;

    clock_t start = clock();
    qsort(a1, 1000, sizeof(int), cmp);
    printf("Time for array size 1000: %g secs\n",
            (double)(clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(a2, 10000, sizeof(int), cmp);
    printf("Time for array size 10000: %g secs\n",
            (double)(clock() - start) / CLOCKS_PER_SEC);

    start = clock();
    qsort(a3, 100000, sizeof(int), cmp);
    printf("Time for array size 100000: %g secs\n",
            (double)(clock() - start) / CLOCKS_PER_SEC);

	exit(EXIT_SUCCESS);
}
