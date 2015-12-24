#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *my_strdup(const char *s)
{
    char *dup = malloc(strlen(s) + 1);
    if(dup == NULL)
        return NULL;
    strcpy(dup, s);
    return dup;
}

int main()
{
    const char *str = "xyz";

    char *dup = my_strdup(str);
    puts(dup);
    free(dup);

    exit(EXIT_SUCCESS);
}
