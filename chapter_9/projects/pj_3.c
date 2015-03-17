#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void generate_random_walk(char walk[10][10])
{
    char token = 'A';
    unsigned char pos_x, pos_y;

    for(char *p = *walk; p < *(walk + 10) + 10; p++)
        *p = '.';

    srand(time(NULL));
    pos_x = rand() % 10;
    pos_y = rand() % 10;
    walk[pos_y][pos_x] = token;

    while(++token <= 'Z') {
        if(
              (pos_x - 1 < 0 || isupper(walk[pos_y][pos_x - 1])) &&
              (pos_x + 1 > 9 || isupper(walk[pos_y][pos_x + 1])) &&
              (pos_y - 1 < 0 || isupper(walk[pos_y - 1][pos_x])) &&
              (pos_y + 1 > 9 || isupper(walk[pos_y + 1][pos_x]))
          )
            break;

        while(true) {
            switch(rand() % 4) {
                case UP:
                    if(pos_y - 1 < 0 || isupper(walk[pos_y - 1][pos_x]))
                        continue;
                    walk[--pos_y][pos_x] = token;
                    goto move_done;
                case RIGHT:
                    if(pos_x + 1 > 9 || isupper(walk[pos_y][pos_x + 1]))
                        continue;
                    walk[pos_y][++pos_x] = token;
                    goto move_done;
                case DOWN:
                    if(pos_y + 1 > 9 || isupper(walk[pos_y + 1][pos_x]))
                        continue;
                    walk[++pos_y][pos_x] = token;
                    goto move_done;
                case LEFT:
                    if(pos_x - 1 < 0 || isupper(walk[pos_y][pos_x - 1]))
                        continue;
                    walk[pos_y][--pos_x] = token;
                    goto move_done;
            }
        }
        move_done: {}
    }
}


void print_array(const char walk[10][10])
{
    for(int row = 0; row < 10; row++) {
        for(int col = 0; col < 10; col++) {
            putchar(walk[row][col]);
            putchar(' ');
        }
        putchar('\n');
    }
    putchar('\n');
}


int main()
{
    char walk[10][10];
    generate_random_walk(walk);
    print_array((const char (*)[10]) walk);

    return 0;
}
