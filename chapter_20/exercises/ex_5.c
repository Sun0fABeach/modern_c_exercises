#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MK_COLOR(red, green, blue) \
    ((red) | (long)(green) << 8 | (long)(blue) << 16)
#define GET_RED(color) ((color) & 255)
#define GET_GREEN(color) ((color) >> 8 & 255)
#define GET_BLUE(color) ((color) >> 16 & 255)

int main()
{
    long color = MK_COLOR(64, 128, 172);
    printf("red: %ld, green: %ld, blue: %ld\n",
            GET_RED(color), GET_GREEN(color), GET_BLUE(color));

    exit(EXIT_SUCCESS);
}
