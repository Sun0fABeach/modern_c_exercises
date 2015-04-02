#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while(--argc)
        printf("%s ", argv[argc]);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
