#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 30
#define MAX_CHARS 20

int main()
{
    char c, buf[MAX_WORDS][MAX_CHARS+1], punct = 0;
    int word, pos;

    printf("Enter a sentence: ");
    for(word = 0; word < MAX_WORDS && !punct; word++) {
        pos = 0;
        while(isspace(c = getchar()))
            ;
        do {
            if(strchr(".!?", c)) {
                punct = c;
                break;
            }
            buf[word][pos++] = c;
            c = getchar();
        } while(pos < MAX_CHARS && !isspace(c));
        buf[word][pos] = '\0';
    }

    printf("Reversal of the sentence: ");
    while(word--) {
        printf(buf[word]);
        if(word && *buf[word])
            putchar(' ');
    }
    if(punct) putchar(punct);
    putchar('\n');

    exit(EXIT_SUCCESS);
}
