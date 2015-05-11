#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *duplicate(char *str)
{
    char *copy = malloc((strlen(str)+1) * sizeof(char));
    if(!copy) return NULL;
    strcpy(copy, str);
    return copy;
}


int main()
{
    char *str = "blahblah";
    char *dup = duplicate(str);
    puts(dup);
    free(dup);

    exit(EXIT_SUCCESS);
}
