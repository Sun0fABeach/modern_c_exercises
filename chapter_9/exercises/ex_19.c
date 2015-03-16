#include <stdio.h>
#include <stdlib.h>

void pb(int n)
{
    if(n) {
        pb(n / 2);
        putchar('0' + n % 2);
    }
}

int main()
{
    int n;

    printf("Enter integer: ");
    scanf("%d", &n);
    pb(n);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
