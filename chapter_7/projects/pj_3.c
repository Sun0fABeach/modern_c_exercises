#include <stdio.h>

int main() {
    double n, sum = 0.0;

    puts("This program sums a series of doubles.");
    printf("Enter doubles (0 to terminate): ");

    scanf("%lf", &n);
    while(n != 0.0) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);

    return 0;
}
