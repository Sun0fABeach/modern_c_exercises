#include <stdio.h>

int main() {
    char chess_board[8][8];

    for(int row = 0; row < 8; row++)
        for(int col = 0; col < 8; col++)
            chess_board[row][col] = (row + col) % 2 ? 'R' : 'B';

    for(int row = 0; row < 8; row++) {
        for(int col = 0; col < 8; col++)
            printf("%c ", chess_board[row][col]);
        putchar('\n');
    }

    return 0;
}
