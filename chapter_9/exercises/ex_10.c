#include <stdio.h>
#include <stdlib.h>

int largest(int n, int a[n])
{
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

double average(int n, int a[n])
{
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += a[i];
    return (double) sum / n;
}

int num_pos(int n, int a[n])
{
    int pos_els = 0;
    for(int i = 0; i < n; i++)
        if(a[i] >= 0)
            pos_els++;
    return pos_els;
}


int main()
{
    int a[10] = {0,1,2,8,-1,-4,-5,7,3,0};

    printf("largest: %d\n", largest(10, a));
    printf("average: %lf\n", average(10, a));
    printf("num pos: %d\n", num_pos(10, a));

    exit(EXIT_SUCCESS);
}
