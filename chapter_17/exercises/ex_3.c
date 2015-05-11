#include <stdio.h>
#include <stdlib.h>


int *create_array(int n, int initial_value)
{
    int *a = malloc(n * sizeof(int));
    if(!a) return NULL;
    for(int i = 0; i < n; i++)
        a[i] = initial_value;
    return a;
}


int main()
{
    int *a = create_array(10, 99);

    for(int i = 0; i < 10; i++)
        printf("%d ", a[i]);
    putchar('\n');

    free(a);

    exit(EXIT_SUCCESS);
}
