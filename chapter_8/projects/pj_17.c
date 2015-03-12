#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main() {
    unsigned short size;

    puts("This program creates a magic square of the specified size.");
    puts("The size must be an odd positive number between 1 and 99.");
    while(true) {
        printf("Enter size of magic square: ");
        scanf("%hu", &size);
        if(size % 2 && size <= 99)
            break;
        puts("Learn how to read!");
    }

    unsigned short square[size][size];
    unsigned short amount_nums = size * size;

    memset(*square, 0, amount_nums * sizeof(amount_nums));

    unsigned char row = 0, col = size/2;
    for(int n = 1; n <= amount_nums; n++) {
        square[row][col] = n;
        row = (row == 0) ? size - 1 : row - 1;
        col = (col == size - 1) ? 0 : col + 1;
        if(square[row][col])
            row++;
    }

    for(int row = 0; row < size; row++) {
        for(int col = 0; col < size; col++)
            printf("%-4d", square[row][col]);
        putchar('\n');
    }

    exit(EXIT_SUCCESS);
}
