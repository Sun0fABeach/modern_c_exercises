#include <stdio.h>

int main() {
    int n;

    puts("This program prints a table of squares.");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    for(short i = 1; i <= n; i++)
        printf(" %-10hd%10hd\n", i, i * i);

    return 0;
}
