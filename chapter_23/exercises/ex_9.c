#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    if(strchr("abc", 'a'))
        puts("Found");
    if(!strchr("abc", 'd'))
        puts("Not found");

    exit(EXIT_SUCCESS);
}
