#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int red;
    int green;
    int blue;
} Color;


Color make_color(int red, int green, int blue)
{
    if(red < 0) red = 0;
    else if(red > 255) red = 255;
    if(green < 0) green = 0;
    else if(green > 255) green = 255;
    if(blue < 0) blue = 0;
    else if(blue > 255) blue = 255;
    return (Color){red, green, blue};
}


int getRed(Color c)
{
    return c.red;
}


bool equalColor(Color c1, Color c2)
{
    return c1.red == c2.red && c1.green == c2.green && c1.blue == c2.blue;
}


Color brighter(Color c)
{
    if(c.red == 0 && c.green == 0 && c.blue == 0)
        return (Color){3, 3, 3};

    int red = c.red, green = c.green, blue = c.blue;

    if(red < 3) red = 3;
    if(green < 3) green = 3;
    if(blue < 3) blue = 3;

    red /= 0.7;
    green /= 0.7;
    blue /= 0.7;

    return make_color(red, green, blue);
}


Color darker(Color c)
{
    return (Color){c.red * 0.7, c.green * 0.7, c.blue * 0.7};
}


int main()
{
    Color c = make_color(2, 45, 234);
    Color b = brighter(c);
    Color d = darker(c);
    printf("Brighter: %d %d %d\n", b.red, b.green, b.blue);
    printf("Darker: %d %d %d\n", d.red, d.green, d.blue);

    exit(EXIT_SUCCESS);
}
