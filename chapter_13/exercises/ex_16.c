#include <stdio.h>
#include <stdlib.h>

int count_spaces(const char *s)
{
    int count = 0;
    while(*s++ == ' ') count ++;
    return count;
}

int main()
{
    printf("%d\n", count_spaces("  asdf"));

    exit(EXIT_SUCCESS);
}
