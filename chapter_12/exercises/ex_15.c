#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temperatures[7][24] = {[4] = {[3] = 32}};

    for(int *p = *(temperatures + 4); p < *(temperatures + 4) + 24; p++)
        printf("%d ", *p);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
