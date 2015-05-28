#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int sum(int f(int), int start, int end)
{
    int sum = 0;
    while(start <= end)
        sum += f(start++);
    return sum;
}


int g(int i)
{
    return i*2;
}


int main()
{
    printf("Sum: %d\n", sum(g, 2, 5));

    exit(EXIT_SUCCESS);
}
