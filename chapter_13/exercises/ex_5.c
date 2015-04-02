#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

void capitalize(char *s)
{
    bool in_word = false;

    while(*s) {
        if(in_word) {
            if(isspace(*s))
                in_word = false;
        } else {
            if(!isspace(*s)) {
                *s = toupper(*s);
                in_word = true;
            }
        }
        s++;
    }
}

int main()
{
    char buff[20];

    printf("Type a line: ");
    fgets(buff, 20, stdin);

    capitalize(buff);
    printf("Capitalized: |%s|\n", buff);

    exit(EXIT_SUCCESS);
}
