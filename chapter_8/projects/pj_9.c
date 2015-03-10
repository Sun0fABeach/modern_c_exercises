#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int main() {
    char a[10][10] = {  {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                        {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
                     };
    char token = 'A';
    unsigned char pos_x, pos_y;

    srand(time(NULL));
    pos_x = rand() % 10;
    pos_y = rand() % 10;
    a[pos_y][pos_x] = token;

    for(int row = 0; row < 10; row++) {
        for(int col = 0; col < 10; col++) {
            putchar(a[row][col]);
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');

    while(++token <= 'Z') {
        if(
              (pos_x - 1 < 0 || isupper(a[pos_y][pos_x - 1])) &&
              (pos_x + 1 > 9 || isupper(a[pos_y][pos_x + 1])) &&
              (pos_y - 1 < 0 || isupper(a[pos_y - 1][pos_x])) &&
              (pos_y + 1 > 9 || isupper(a[pos_y + 1][pos_x]))
          )
            break;

        while(true) {
            switch(rand() % 4) {
                case UP:
                    if(pos_y - 1 < 0 || isupper(a[pos_y - 1][pos_x]))
                        continue;
                    a[--pos_y][pos_x] = token;
                    goto move_done;
                case RIGHT:
                    if(pos_x + 1 > 9 || isupper(a[pos_y][pos_x + 1]))
                        continue;
                    a[pos_y][++pos_x] = token;
                    goto move_done;
                case DOWN:
                    if(pos_y + 1 > 9 || isupper(a[pos_y + 1][pos_x]))
                        continue;
                    a[++pos_y][pos_x] = token;
                    goto move_done;
                case LEFT:
                    if(pos_x - 1 < 0 || isupper(a[pos_y][pos_x - 1]))
                        continue;
                    a[pos_y][--pos_x] = token;
                    goto move_done;
            }
        }
        move_done:
        for(int row = 0; row < 10; row++) {
            for(int col = 0; col < 10; col++) {
                putchar(a[row][col]);
                putchar(' ');
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
