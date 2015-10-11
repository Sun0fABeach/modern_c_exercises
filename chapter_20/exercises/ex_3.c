#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MK_COLOR(red, green, blue) \
    ((red) | (long)(green) << 8 | (long)(blue) << 16)

int main()
{
    long color = MK_COLOR(64, 128, 172);
    printf("red: %ld, green: %ld, blue: %ld\n",
            color & 255, color >> 8 & 255, color >> 16 & 255);

    exit(EXIT_SUCCESS);
}
