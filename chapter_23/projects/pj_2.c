#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main()
{
    int c;

    while(true) {
        while(isspace(c = getchar()))
            ;
        while(true) {
            if(c == EOF)
                exit(EXIT_SUCCESS);
            if(putchar(c) == '\n')
                break;
            c = getchar();
        }
    }
}
