#include <stdio.h>

int main() {
    int n;

    puts("This program prints a table of squares.");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for(int i = 1, odd = 3, square = 1; i <= n; square += odd, odd += 2, i++) {
        printf("%10d%10d\n", i, square);
    }

    return 0;
}
