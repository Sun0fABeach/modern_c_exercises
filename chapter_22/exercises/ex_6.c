#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int i = 1;
    printf("widget%s\n", i == 1 ? "" : "s");
    i = 3;
    printf("widget%s\n", i == 1 ? "" : "s");

    exit(EXIT_SUCCESS);
}
