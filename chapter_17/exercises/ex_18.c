#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


typedef struct part {
    char name[10];
} Part;


int compare_parts(const void *p1, const void *p2)
{
    return -strcmp( ((Part *)p1)->name, ((Part *)p2)->name );
}

int main()
{
    Part parts[4] = {{"asdf"}, {"qwer"}, {"yxcv"}, {"oiuz"}};

    qsort(parts, 4, sizeof(Part), compare_parts);

    for(Part *p = parts; p < parts + 4; p++)
        puts(p->name);

    exit(EXIT_SUCCESS);
}
