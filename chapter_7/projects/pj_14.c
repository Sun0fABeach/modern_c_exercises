#include <stdio.h>
#include <math.h>

int main() {
    double x, y, avg = 1.0;

    printf("Enter a positive number: ");
    scanf("%lf", &x);

    printf("\n%-11s%-11s%-11s%-11s\n", "x", "y", "x/y", "avg(x, x/y)");
    puts("--------------------------------------------");

    do {
        y = avg;
        avg = (y + x/y) / 2;
        printf("%-11.6g%-11.6g%-11.6g%-11.6g\n", x, y, x/y, avg);
    } while(fabs(y - avg) >= .00001 * avg);

    printf("\nBest guess for square root of %g: %g\n\n", x, avg);

    return 0;
}
