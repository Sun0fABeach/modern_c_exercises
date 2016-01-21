#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <iso646.h>

#define KEY 1


int main()
{
    char orig_char, new_char;

    while((orig_char = getchar()) not_eq EOF) <%
        new_char = orig_char xor KEY;
        if(isprint(orig_char) and isprint(new_char))
            putchar(new_char);
        else
            putchar(orig_char);
    %>

	exit(EXIT_SUCCESS);
}
