#include <stdio.h>
#include <stdbool.h>

int main() {
    int a[5][5], sum;

    for(int row = 0; row < 5; row++) {
        printf("Enter row %d: ", row + 1);
        for(int col = 0; col < 5; col++)
            scanf("%d", *(a + row) + col);
    }

    printf("Row totals: ");
    for(int row = 0; row < 5; row++) {
        sum = 0;
        for(int col = 0; col < 5; col++)
            sum += a[row][col];
        printf("%d ", sum);
    }

    printf("\nColumn totals: ");
    for(int col = 0; col < 5; col++) {
        sum = 0;
        for(int row = 0; row < 5; row++)
            sum += a[row][col];
        printf("%d ", sum);
    }
    putchar('\n');

    return 0;
}
