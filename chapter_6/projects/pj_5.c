#include <stdio.h>

int main() {
    int n;
    const char *minus = "";

    printf("Enter a number: ");
    scanf("%d", &n);
    if(n < 0) {
       minus = "-";
       n = -n;
    }

    printf("The reversal is: %s", minus);

    do printf("%d", n % 10); while (n /= 10);
    putchar('\n');

    return 0;
}
