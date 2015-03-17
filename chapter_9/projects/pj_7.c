#include <stdio.h>
#include <stdlib.h>


int power(int x, int n)
{
    if(!n)    return 1;
    if(n % 2) return x * power(x, n - 1);

    int tmp = power(x, n / 2);
    return tmp * tmp;
}

int main()
{
    int base, exp;

    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exp: ");
    scanf("%d", &exp);

    printf("%d to the power of %d equals: %d\n", base, exp, power(base, exp));

    exit(EXIT_SUCCESS);
}
