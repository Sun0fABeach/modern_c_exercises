#include <stdio.h>
#include <stdlib.h>


struct point { int x, y; };
struct rectangle { struct point upper_left, lower_right; };
struct rectangle *p;

int main()
{
    p = &(struct rectangle){ {10, 25}, {20, 15} };

    printf(
        "%d/%d %d/%d\n",
        p->upper_left.x, p->upper_left.y, p->lower_right.x, p->lower_right.y
    );

    exit(EXIT_SUCCESS);
}
