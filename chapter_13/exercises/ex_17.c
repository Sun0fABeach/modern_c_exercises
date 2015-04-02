#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool test_extension(const char *file_name, const char *extension)
{
    char *period = strrchr(file_name, '.');

    if(!period)
        return false;
    while(toupper(*++period) == toupper(*extension++))
        if(!*period)
            return true;
    return false;
}

int main()
{
    printf("%hhd\n", test_extension("shit.txt", "TXT"));
    printf("%hhd\n", test_extension("shit.tx", "TXT"));
    printf("%hhd\n", test_extension("shit", "TXT"));
    printf("%hhd\n", test_extension("sh", "TXT"));

    exit(EXIT_SUCCESS);
}
