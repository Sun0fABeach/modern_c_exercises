#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void create_magic_square(unsigned short n, unsigned short magic_square[][n])
{
    unsigned short amount_nums = n * n;

    memset(*magic_square, 0, amount_nums * sizeof(amount_nums));

    unsigned char row = 0, col = n / 2;
    for(int i = 1; i <= amount_nums; i++) {
        magic_square[row][col] = i;
        row = (row == 0) ? n - 1 : row - 1;
        col = (col == n - 1) ? 0 : col + 1;
        if(magic_square[row][col])
            row++;
    }
}

void print_magic_square(unsigned short n, unsigned short magic_square[][n])
{
    for(int row = 0; row < n; row++) {
        for(int col = 0; col < n; col++)
            printf("%-4d", magic_square[row][col]);
        putchar('\n');
    }
}

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

    unsigned short magic_square[size][size];
    create_magic_square(size, magic_square);
    print_magic_square(size, magic_square);

    exit(EXIT_SUCCESS);
}
