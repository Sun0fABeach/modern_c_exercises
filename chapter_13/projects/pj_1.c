#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define WORD_MAX 20

int main()
{
    char buff[WORD_MAX + 1], smallest[WORD_MAX] = "", largest[WORD_MAX] = "";
    unsigned char sm_len = WORD_MAX, lrg_len = 0, i;

    while(true) {
        printf("Enter word: ");
        for(i = 0; i < WORD_MAX; i++) {
            if((buff[i] = getchar()) == '\n') {
                buff[i] = '\0';
                break;
            }
        }
        if(i == WORD_MAX)
            buff[i] = '\0';
        else if(i == 4)
            break;

        if(i < sm_len) {
            sm_len = i;
            strcpy(smallest, buff);
        }
        if(i > lrg_len) {
            lrg_len = i;
            strcpy(largest, buff);
        }
    }

    if(*smallest) {
        printf("Smallest word: %s\n", smallest);
        printf("Largest word: %s\n", largest);
    }

    exit(EXIT_SUCCESS);
}
