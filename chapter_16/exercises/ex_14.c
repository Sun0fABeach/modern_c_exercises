#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    enum {RECTANGLE, CIRCLE} kind;
    Point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } form;
} Shape;


int area(Shape s)
{
    if(s.kind == RECTANGLE)
        return s.form.rectangle.height * s.form.rectangle.width;
    else
        return s.form.circle.radius * s.form.circle.radius * M_PI;
}


Shape move(Shape s, int dir_x, int dir_y)
{
    s.center.x += dir_x;
    s.center.y += dir_y;
    return s;
}


Shape scale(Shape s, double factor)
{
    if(s.kind == RECTANGLE) {
        s.form.rectangle.height *= factor;
        s.form.rectangle.width *= factor;
    } else
        s.form.circle.radius *= factor;
    return s;
}


int main()
{
    printf(
        "Rectangle area: %d\n", area(
            (Shape){RECTANGLE, {3, 3}, .form.rectangle = {3, 4}}
        )
    );
    printf(
        "Circle area: %d\n", area(
            (Shape){CIRCLE, {3, 3}, .form.circle = {5}}
        )
    );
    Shape s = {CIRCLE, {3, 3}, .form.circle = {5}};
    printf("Circle: center %d/%d, radius: %d\n",
        s.center.x, s.center.y, s.form.circle.radius
    );
    s = move(s, 2, 4);
    printf("Moved 2/4: %d/%d\n", s.center.x, s.center.y);
    s = scale(s, 1.5);
    printf("Scaled 1.5: %d\n", s.form.circle.radius);

    exit(EXIT_SUCCESS);
}
