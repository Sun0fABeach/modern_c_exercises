#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 2, square = 4; square <= n; i += 2, square = i * i)
        printf("%d\n", square);

    return 0;
}
