#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum direction {NORTH = 11, SOUTH, EAST = 1, WEST};

    printf("%d %d %d %d\n", NORTH, SOUTH, EAST, WEST);

    exit(EXIT_SUCCESS);
}
