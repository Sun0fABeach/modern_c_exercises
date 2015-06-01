#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 20


typedef struct word {
    char *word;
    struct word *next;
} Word;


static void destroy_word(Word *to_destroy);


Word *line = NULL, *cur_word = NULL;
int line_len = 0;
int num_words = 0;


void add_word(const char *word)
{
    Word *new_word = malloc(sizeof(Word));
    new_word->word = malloc((strlen(word)+1) * sizeof(char));
    strcpy(new_word->word, word);
    new_word->next = NULL;

    if(cur_word) {
        cur_word->next = new_word;
        cur_word = cur_word->next;
    } else
        line = cur_word = new_word;

    line_len += strlen(word);
    if(num_words > 0)
        line_len++; //whitespace between words
    num_words++;
}

int space_remaining(void)
{
  return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces = MAX_LINE_LEN - line_len;

    while(line) {
        Word *to_delete = line;

        printf(line->word);
        int spaces_to_insert = extra_spaces / num_words;
        for (int i = 1; i <= spaces_to_insert + 1; i++)
            putchar(' ');

        extra_spaces -= spaces_to_insert;
        num_words--;
        line = line->next;
        destroy_word(to_delete);
    }
    cur_word = NULL;
    line_len = 0;
    putchar('\n');
}

void flush_line(void)
{
    while(line) {
        Word *to_delete = line;
        printf(line->word);
        if(--num_words > 0)
            putchar(' ');
        line = line->next;
        destroy_word(to_delete);
    }
    cur_word = NULL;
    line_len = 0;
    putchar('\n');
}

static void destroy_word(Word *to_destroy)
{
    free(to_destroy->word);
    free(to_destroy);
}
