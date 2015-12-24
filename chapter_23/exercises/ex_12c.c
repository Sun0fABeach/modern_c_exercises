#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *strlwr(char *s)
{
    char *p = s;
    while((*p = tolower(*p)))
        ++p;
    return s;
}

int main()
{
    char s1[] = "x,Y/z";
    puts(strlwr(s1));

    char s2[] = "";
    puts(strlwr(s2));

    exit(EXIT_SUCCESS);
}
