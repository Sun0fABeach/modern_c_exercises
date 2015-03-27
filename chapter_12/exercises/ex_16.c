#include <stdio.h>
#include <stdlib.h>

int find_largest(int *a, int n)
{
    int max = *a;
    while(--n)
        if(*++a > max)
            max = *a;
    return max;
}

int main()
{
    int temperatures[7][24] = {[4] = {[3] = 32}, [6] = {12}};

    for(int (*row)[24] = temperatures; row < temperatures + 7; row++)
        printf("Largest of day %td: %d\n",
                row - temperatures + 1, find_largest(*row, 24));

    exit(EXIT_SUCCESS);
}
