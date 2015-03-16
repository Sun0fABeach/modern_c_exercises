#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define SWAP(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

void selection_sort(int a[], int size)
{
    if(size <= 1) return;

    int max_i = 0;
    for(int i = 1; i < size; i++)
        if(a[i] > a[max_i])
            max_i = i;
    if(max_i != size - 1)
        SWAP(a[max_i], a[size - 1]);

    selection_sort(a, size - 1);
}

int main()
{
    int a[10];

    printf("Enter 10 integers: ");
    for(int i = 0; i < 10; i++)
        scanf("%d", a + i);

    selection_sort(a, 10);
    printf("Sorted: ");
    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
