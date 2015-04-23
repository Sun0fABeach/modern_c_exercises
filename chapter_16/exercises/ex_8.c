#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;

const Color MAGENTA = {.red = 255, .blue = 255};

int main()
{
    printf("%d %d %d\n", MAGENTA.red, MAGENTA.green, MAGENTA.blue);

    exit(EXIT_SUCCESS);
}
