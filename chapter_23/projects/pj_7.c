#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define PUNCTS ".,?!"


int main()
{
    unsigned int count = 0;

    while(true) {
        int c = getchar();

        if(c == EOF)
            break;

        while(strchr(PUNCTS, c)) {
            if(isspace(c = getchar())) {
                ++count;
                break;
            }
            if(c == EOF)
                goto end;
        }
    }

    end:
    printf("Number of sentences: %u\n", count);

    exit(EXIT_SUCCESS);
}
