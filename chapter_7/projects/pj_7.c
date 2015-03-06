#include <stdio.h>
#include <stdbool.h>

int main() {
    int nom1, denom1, nom2, denom2, m, n, rem, test;
    char operator;

    printf("Enter an equation containing two fractions: ");
    test = scanf("%d /%d %c%d /%d", &nom1, &denom1, &operator, &nom2, &denom2);
    if(test != 5) {
        puts("Invalid input!");
        return 1;
    }

    switch(operator) {
        case '+':
            nom1 = nom1 * denom2 + nom2 * denom1;
            denom1 *= denom2;
            break;
        case '-':
            nom1 = nom1 * denom2 - nom2 * denom1;
            denom1 *= denom2;
            break;
        case '*':
            nom1 *= nom2;
            denom1 *= denom2;
            break;
        case '/':
            nom1 *= denom2;
            denom1 *= nom2;
            break;
        default:
            printf("Unknown operator '%c'!\n", operator);
            return 1;
    }

    m = nom1;
    n = denom1;

    while(n) {
        rem = m % n;
        m = n;
        n = rem;
    }

    printf("Result in lowest terms: %d/%d\n", nom1/m, denom1/m);

    return 0;
}
