#include <stdio.h>
#include <stdbool.h>

int main() {
    double e = 1.0, epsilon, term;
    int i = 0, fac = 1;

    printf("Enter epsilon: ");
    scanf("%lf", &epsilon);

    while(true) {
        fac *= ++i;
        if((term = 1.0/fac) < epsilon)
            break;
        e += term;
    }

    printf("Approximated e: %lf\n", e);

    return 0;
}
