#include <stdio.h>
#include <stdbool.h>

int main() {
    bool digit_seen[10] = {false};
    bool digit_mentioned[10] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    printf("Repeated digit(s): ");
    while(n > 0) {
        digit = n % 10;
        if(digit_seen[digit]) {
            if(!digit_mentioned[digit]) {
                printf("%d ", digit);
                digit_mentioned[digit] = true;
            }
        } else {
            digit_seen[digit] = true;
        }
        n /= 10;
    }

    putchar('\n');

    return 0;
}
