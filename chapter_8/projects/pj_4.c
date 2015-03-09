#include <stdio.h>

#define N 10
#define length(a) ( (int) (sizeof(a) / sizeof(a[0])) )

int main() {
    int a[N];

    printf("Enter %d numbers: ", N);
    for(int i = 0; i < length(a); i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");
    for(int i = length(a) - 1; i >= 0; i--)
        printf("%d ", a[i]);

    putchar('\n');

    return 0;
}
