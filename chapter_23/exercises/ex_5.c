#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


long int hextol(const char *s)
{
    if(*s == '0' && *(s+1) == 'x')
        s += 2;

    if(!*s) return -1;

    for(const char *p = s; *p; p++)
        if(!isxdigit(*p))
            return -1;

    return strtol(s, (char **)&(char *[1]){}, 16);
}


int main()
{
    printf("%s: %ld\n", "0x123", hextol("0x123"));
    printf("%s: %ld\n", "123", hextol("123"));
    printf("%s: %ld\n", "a123", hextol("a123"));
    printf("%s: %ld\n", "z123", hextol("z123"));
    printf("%s: %ld\n", "123z", hextol("123z"));
    printf("%s: %ld\n", "0x", hextol("0x"));
    printf("%s: %ld\n", "", hextol(""));

    exit(EXIT_SUCCESS);
}
