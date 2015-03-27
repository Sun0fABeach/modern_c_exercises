#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 100

int main()
{
    char buf[BUFSIZE], punct = 0, *pos, *word_end;

    printf("Enter a sentence: ");
    for(pos = buf; pos < buf + BUFSIZE; pos++) {
        *pos = getchar();
        if(strchr(".!?", *pos)) {
            punct = *pos;
            break;
        }
    }

    printf("Reversal of the sentence: ");
    while(true) {
        do { pos--; } while(pos >= buf && isspace(*pos));
        word_end = pos;

        while(pos >= buf && !isspace(*pos))
            pos--;

        for(char *word_pos = pos + 1; word_pos <= word_end; word_pos++)
            putchar(*word_pos);

        if(pos >= buf)
            putchar(' ');
        else break;
    }

    if(punct) putchar(punct);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
