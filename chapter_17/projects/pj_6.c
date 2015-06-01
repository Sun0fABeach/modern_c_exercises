#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WORD_LEN 20
#define MAX_WORDS 10


static inline void read_word(char *buf)
{
    char *p;

    fgets(buf, WORD_LEN+1, stdin);
    if((p = strchr(buf, '\n')))
        *p = '\0';
    else
        while(getchar() != '\n')
            ;
}


static inline int comp(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}


int main(void)
{
    char word[WORD_LEN + 1];
    char *word_list[MAX_WORDS];
    int i;

    for(i = 0; i < MAX_WORDS; i++) {
        printf("Enter word: ");
        read_word(word);
        if(!*word) break;
        word_list[i] = malloc((strlen(word)+1) * sizeof(char));
        strcpy(word_list[i], word);
    }

    qsort(word_list, i, sizeof(char *), comp);

    printf("In sorted order: ");
    for(int j = 0; j < i; j++) {
        printf("%s ", word_list[j]);
        free(word_list[j]);
    }
    putchar('\n');

    exit(EXIT_SUCCESS);
}
