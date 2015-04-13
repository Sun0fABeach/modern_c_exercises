#include <stdio.h>
#include <stdlib.h>

#define TOUPPER(c) ('a'<=(c)&&(c)<='z' ? (c)-'a'+'A' : (c))

int main()
{
    const char *s = "abcd";
    int i = 0;
    putchar(TOUPPER(s[++i]));
    putchar('\n');

    s = "0123";
    i = 0;
    putchar(TOUPPER(s[++i]));
    putchar('\n');

    exit(EXIT_SUCCESS);
}
