#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    const char *cmpstr = "foo,bar,baz";
    const char *str = "bar";
    // only works correctly if str doesn't contain ','

    if(strstr(cmpstr, str) != NULL)
        puts("found");

    str = "yxc";

    if(strstr(cmpstr, str) == NULL)
        puts("not found");

    exit(EXIT_SUCCESS);
}
