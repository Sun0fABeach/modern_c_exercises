#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if(argc < 2) {
        puts("usage: pj_4 filename");
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch;
    unsigned int chars = 0, words = 0, lines = 0;
    bool in_word = false;

    while((ch = getc(fp)) != EOF) {
        chars++;
        if(in_word) {
            if(isspace(ch)) {
                in_word = false;
            }
        } else {
            if(!isspace(ch)) {
                in_word = true;
                words++;
            }
        }
        if(ch == '\n')
            lines++;
    }

    if(ferror(fp))
        fprintf(stderr, "stopped reading file %s due to error\n", argv[argc]);
    fclose(fp);

    printf("lines: %u, words: %u, chars: %u\n", lines, words, chars);

    exit(EXIT_SUCCESS);
}
