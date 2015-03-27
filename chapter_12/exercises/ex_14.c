#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool search(const int a[], int n, int key)
{
    while(n--)
        if(*a++ == key)
            return true;
    return false;
}

int main()
{
    int temperatures[7][24] = {[4] = {[3] = 32}};

    printf("contained: %hhd\n", search(*temperatures, 124 * 7, 32));
    printf("contained: %hhd\n", search(*temperatures, 124 * 7, 34));

    exit(EXIT_SUCCESS);
}
