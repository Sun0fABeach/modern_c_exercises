#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    return n <= 1 ? 1 : n * fact(n - 1);
}

int main()
{
    printf("Factorial of 5: %d\n", fact(5));

    exit(EXIT_SUCCESS);
}
