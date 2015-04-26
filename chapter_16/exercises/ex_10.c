#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {int x, y;} Point;
typedef struct {Point upper_left, lower_right;} Rectangle;

int area(Rectangle r)
{
    return (r.lower_right.x - r.upper_left.x) *
           (r.lower_right.y - r.upper_left.y);
}

Point center(Rectangle r)
{
    int len_x = r.lower_right.x - r.upper_left.x;
    int len_y = r.lower_right.y - r.upper_left.y;
    return (Point){r.upper_left.x + len_x/2, r.upper_left.y + len_y/2};
}

Rectangle move(Rectangle r, int x_dir, int y_dir)
{
    r.upper_left.x += x_dir;
    r.upper_left.y += y_dir;
    r.lower_right.x += x_dir;
    r.lower_right.y += y_dir;
    return r;
}


bool contains(Rectangle r, Point p)
{
    return r.upper_left.x <= p.x && r.upper_left.y <= p.y &&
           r.lower_right.x >= p.x && r.lower_right.y >= p.y;
}


int main()
{
    printf("Area: %d\n", area((Rectangle){{1, 2}, {3, 4}}));
    Point p = center((Rectangle){{1, 2}, {5, 6}});
    printf("Center: %d/%d\n", p.x, p.y);
    Rectangle r = move((Rectangle){{1, 2}, {5, 6}}, 3, 3);
    printf("Moved: %d/%d %d/%d\n",
        r.upper_left.x, r.upper_left.y, r.lower_right.x, r.lower_right.y
    );
    printf("Contains: %hhu\n", contains(r, (Point){7, 9}));

    exit(EXIT_SUCCESS);
}
