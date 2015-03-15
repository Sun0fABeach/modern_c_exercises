#include <stdio.h>
#include <stdlib.h>

int gcd(int m, int n);

int main() {
    int m, n;

    printf("Enter two integers: ");
    scanf("%d%d", &m, &n);

    printf("Greatest common divisor: %d\n", gcd(m, n));

    exit(EXIT_SUCCESS);
}

int gcd(int m, int n)
{
    int rem;
    while(n) {
        rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}
