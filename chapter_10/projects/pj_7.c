#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DIGITS 10

const int segments[10][7] = {{1, 1, 1, 1, 1, 1, 0},
                             {0, 1, 1, 0, 0, 0, 0},
                             {1, 1, 0, 1, 1, 0, 1},
                             {1, 1, 1, 1, 0, 0, 1},
                             {0, 1, 1, 0, 0, 1, 1},
                             {1, 0, 1, 1, 0, 1, 1},
                             {1, 0, 1, 1, 1, 1, 1},
                             {1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 1, 1}};
int display[3][MAX_DIGITS * 4];


void clear_digits_array()
{
    for(int row = 0; row < 3; row++)
        for(int col = 0; col < MAX_DIGITS * 4; col++)
            display[row][col] = ' ';
}

void process_digit(int digit, int position)
{
    const int *seg_code = segments[digit];
    position *= 4;

    if(seg_code[0])
        display[0][position + 1] = '_';
    if(seg_code[1])
        display[1][position + 2] = '|';
    if(seg_code[2])
        display[2][position + 2] = '|';
    if(seg_code[3])
        display[2][position + 1] = '_';
    if(seg_code[4])
        display[2][position]     = '|';
    if(seg_code[5])
        display[1][position]     = '|';
    if(seg_code[6])
        display[1][position + 1] = '_';
}

void print_digits_array()
{
    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < MAX_DIGITS * 4; col++)
            putchar(display[row][col]);
        putchar('\n');
    }
}

int main()
{
    char c;
    int num_position = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while(num_position < 10 && (c = getchar()) != '\n')
        if(isdigit(c))
            process_digit(c - '0', num_position++);

    print_digits_array();

    exit(EXIT_SUCCESS);
}
