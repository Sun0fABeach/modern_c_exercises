#include <stdio.h>
#include <stdlib.h>

int digit(int n, int k);

int main()
{
    int n, k;

    printf("Enter integer: ");
    scanf("%d", &n);
    printf("Enter digit position: ");
    scanf("%d", &k);

    printf("Digit at position %d: %d\n", k, digit(n, k));

    exit(EXIT_SUCCESS);
}

int digit(int n, int k)
{
    if(!k) k = 1;
    while(--k) n /= 10;
    return n % 10;
}
