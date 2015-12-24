#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int numchar(const char *s, const char ch)
{
    int count = 0;

    while(s) {
        if((s = strchr(s, ch)) == NULL)
            break;
        ++s;
        ++count;
    }

    return count;
}


int main()
{
    const char c = 'x';

    printf("%c in %s: %d\n", c, "xyxy", numchar("xyxy", c));
    printf("%c in %s: %d\n", c, "", numchar("", c));
    printf("%c in %s: %d\n", c, "x", numchar("x", c));
    printf("%c in %s: %d\n", c, "xyx", numchar("xyx", c));
    printf("%c in %s: %d\n", c, "yxy", numchar("yxy", c));
    printf("%c in %s: %d\n", c, "xx", numchar("xx", c));
    printf("%c in %s: %d\n", c, "abc", numchar("abc", c));

    exit(EXIT_SUCCESS);
}
