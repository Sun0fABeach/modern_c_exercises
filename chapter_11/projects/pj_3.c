#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void reduce(int numerator, int denominator, int *red_num, int *red_denom)
{
    int rem, n = numerator, m = denominator;

    while(n) {
        rem = m % n;
        m = n;
        n = rem;
    }

    *red_num = numerator / m;
    *red_denom = denominator / m;
}

int main()
{
    int num, denom, red_num, red_denom;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    reduce(num, denom, &red_num, &red_denom);

    printf("In lowest terms: %d/%d\n", red_num, red_denom);

    exit(EXIT_SUCCESS);
}
