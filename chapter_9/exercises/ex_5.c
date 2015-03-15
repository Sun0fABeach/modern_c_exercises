#include <stdio.h>
#include <stdlib.h>

int num_digits(int n);

int main() {
    int n;

    printf("Enter integer: ");
    scanf("%d", &n);

    printf("Number if digits: %d\n", num_digits(n));

    exit(EXIT_SUCCESS);
}

int num_digits(int n)
{
    int count = 0;
    do {
        n /= 10;
        count++;
    } while(n);

    return count;
}
