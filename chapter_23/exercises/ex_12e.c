#include <stdlib.h>
#include <stdio.h>


char *strset(char *s, const char c)
{
    char *p = s;
    while(*p)
        *p++ = c;
    return s;
}

int main()
{
    char s1[] = "abc";
    puts(strset(s1, 'x'));

    char s2[] = "";
    puts(strset(s2, 'x'));

    exit(EXIT_SUCCESS);
}
