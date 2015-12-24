#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main()
{
    char cmpstr[] = "shiznat";

    memset(cmpstr + strlen(cmpstr) - 3, '!', 3);

    puts(cmpstr);

    exit(EXIT_SUCCESS);
}
