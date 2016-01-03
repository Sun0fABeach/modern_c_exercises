#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main()
{
    while(true) {
        int c = getchar();
        if(c == EOF)
            break;
        if(iscntrl(c) && c != '\n')
            putchar('?');
        else
            putchar(c);
    }

    exit(EXIT_SUCCESS);
}
