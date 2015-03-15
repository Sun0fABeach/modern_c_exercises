#include <stdio.h>
#include <stdlib.h>

int fact(int n)
{
    if(n <= 0) return 1;

    int fact = 1;
    while(n) fact *= n--;

    return fact;
}

int main()
{
    printf("Factorial of 5: %d\n", fact(5));

    exit(EXIT_SUCCESS);
}
