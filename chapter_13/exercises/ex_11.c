#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *s1, const char *s2)
{
    while(*s1 == *s2) {
        if(!*s1) return 0;
        s1++, s2++;
    }
    return s1 - s2;
}

int main()
{
    printf("%d\n", strcmp("fo", "foo"));
    printf("%d\n", strcmp("foo", "foo"));
    printf("%d\n", strcmp("fox", "foo"));
    printf("%d\n", strcmp("foo", "fo"));

    exit(EXIT_SUCCESS);
}
