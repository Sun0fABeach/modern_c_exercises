#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define BUFSIZE 100

int main() {
    char buf[BUFSIZE], punct = 0;
    int i, word_length = 0;

    printf("Enter a sentence: ");
    for(i = 0; i < BUFSIZE; i++) {
        buf[i] = getchar();
        if(strchr(".!?", buf[i])) {
            punct = buf[i];
            break;
        }
    }

    printf("Reversal of the sentence: ");
    while(true) {
        do { i--; } while(i >= 0 && isspace(buf[i]));

        while(i >= 0 && !isspace(buf[i])) {
            word_length++;
            i--;
        }
        for(int j = i + 1; word_length; j++, word_length--)
            putchar(buf[j]);

        if(i >= 0)
            putchar(' ');
        else break;
    }

    if(punct) putchar(punct);
    putchar('\n');

    return 0;
}
