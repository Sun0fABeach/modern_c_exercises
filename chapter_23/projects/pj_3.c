#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int main()
{
    int c;
    bool in_word = false;

    while(true) {
        if((c = getchar()) == EOF)
            exit(EXIT_SUCCESS);
        if(in_word) {
            if(!isalnum(c)) {
                in_word = false;
            }
            putchar(c);
        } else {
            if(isalnum(c)) {
                in_word = true;
                putchar(toupper(c));
            } else {
                putchar(c);
            }
        }
    }
}
