#include <stdio.h>
#include <stdbool.h>

int main() {
    unsigned short digit_seen[10] = {0};
    int digit;
    long n;

    while(true) {
        printf("Enter a number: ");
        scanf("%ld", &n);

        if(n <= 0) break;

        while(n > 0) {
            digit = n % 10;
            digit_seen[digit]++;
            n /= 10;
        }

        printf("%-15s", "Digit:");
        for(int i = 0; i < 10; i++)
            printf("%d ", i);
        putchar('\n');

        printf("%-15s", "Occurrences:");
        for(int i = 0; i < 10; i++)
            printf("%d ", digit_seen[i]);
        putchar('\n');
    }

    return 0;
}
