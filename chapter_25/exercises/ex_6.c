#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define KEY 1

int main()
{
    char orig_char, new_char;

    while((orig_char = getchar()) != EOF) ??<
        new_char = orig_char ??' KEY;
        if(isprint(orig_char) && isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    ??>

	exit(EXIT_SUCCESS);
}
