#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int compare(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}


int main()
{
    int a[100] = {[50]=-99, 99, 11, 12, 13, 14, 15, 16, 17, 18};
    qsort(a+50, 50, sizeof(int), compare);

    for(size_t i = 50; i < 100; i++)
        printf("%d ", a[i]);

    exit(EXIT_SUCCESS);
}
