#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


int stricmp(const char *s1, const char *s2)
{
    while(true) {
        char a = tolower(*s1);
        char b = tolower(*s2);
        if(a != b)
            return a - b;
        if(a == '\0')
            return 0;
        ++s1;
        ++s2;
    }
}

int main()
{
    printf("stricmp: %s / %s: %d\n", "xyz", "xyz", stricmp("xyz", "xyz"));
    printf("stricmp: %s / %s: %d\n", "xyz", "xyZ", stricmp("xyz", "xyZ"));
    printf("stricmp: %s / %s: %d\n", "xyz", "xy", stricmp("xyz", "xy"));
    printf("stricmp: %s / %s: %d\n", "xy", "xyz", stricmp("xy", "xyz"));
    printf("stricmp: %s / %s: %d\n", "", "", stricmp("", ""));

    exit(EXIT_SUCCESS);
}
