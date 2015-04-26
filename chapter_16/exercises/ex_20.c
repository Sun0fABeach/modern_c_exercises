#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum {NORTH, SOUTH, EAST, WEST} direction = EAST;

    int x = 1, y = 1;

    switch(direction) {
        case NORTH:
            y--; break;
        case SOUTH:
            y++; break;
        case WEST:
            x--; break;
        case EAST:
            x++; break;
    }

    printf("x: %d, y: %d\n", x, y);

    exit(EXIT_SUCCESS);
}
