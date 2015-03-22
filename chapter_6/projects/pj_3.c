#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main()
{
    int nom, denom, m, n, rem;
    printf("Enter a fraction: ");
    scanf("%d /%d", &nom, &denom);
    m = nom;
    n = denom;

    while(n) {
        rem = m % n;
        m = n;
        n = rem;
    }

    printf("In lowest terms: %d/%d\n", nom/m, denom/m);

    exit(EXIT_SUCCESS);
}
