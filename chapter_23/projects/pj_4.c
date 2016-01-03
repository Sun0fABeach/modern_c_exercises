#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 200


int main()
{
    char buf[MAX_LINE_LEN + 1];
    bool in_word = false;
    short wcount = 0;
    int i;

    for(i = 0; i < MAX_LINE_LEN; ++i) {
        char c;

        if((c = getchar()) == EOF || c == '\n')
            break;
        buf[i] = c;

        if(in_word) {
            if(isspace(c)) {
                in_word = false;
            }
        } else {
            if(!isspace(c)) {
                in_word = true;
                ++wcount;
            }
        }
    }
    buf[i] = '\0';

    if(wcount == 0)
        exit(EXIT_SUCCESS);

    char *words[wcount];
    i = wcount - 1;

    words[i] = strtok(buf, " \t");
    while(--i >= 0)
        words[i] = strtok(NULL, " \t");

    while(++i < wcount)
        printf("%s ", words[i]);

    putchar('\n');

    exit(EXIT_SUCCESS);
}
