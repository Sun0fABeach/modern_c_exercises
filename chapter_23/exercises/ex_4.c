#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


bool is_c_identifier(const char *s)
{
    if(!isalpha(*s) && *s != '_')
        return false;

    while(*++s)
        if(!isalnum(*s) && *s != '_')
            return false;

    return true;
}


int main()
{
    printf("%s: %hhd\n", "asdf", is_c_identifier("asdf"));
    printf("%s: %hhd\n", "", is_c_identifier(""));
    printf("%s: %hhd\n", "_asdf", is_c_identifier("_asdf"));
    printf("%s: %hhd\n", "1asdf", is_c_identifier("1asdf"));
    printf("%s: %hhd\n", "a1sdf", is_c_identifier("a1sdf"));
    printf("%s: %hhd\n", "a_sdf", is_c_identifier("a_sdf"));
    printf("%s: %hhd\n", "_2", is_c_identifier("_2"));

    exit(EXIT_SUCCESS);
}
