#include <stdio.h>

int main() {
    int n, fac = 1;
    double e = 1.0;

    printf("Enter n: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        fac *= i;
        e += 1.0/fac;
    }

    printf("Approximated e: %lf\n", e);

    return 0;
}
