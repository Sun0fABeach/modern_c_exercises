#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

double compute_average_word_length(const char *sentence)
{
    unsigned short count = 0, sum = 0;
    bool in_word = false;

    while(*sentence) {
        if(in_word)
            if(isspace(*sentence++))
                in_word = false;
            else
                sum++;
        else
            if(!isspace(*sentence++)) {
                in_word = true;
                count++;
                sum++;
            }
    }
    return (double)sum / count;
}

int main()
{
    char s[100];

    printf("Enter a sentence: ");
    fgets(s, 100, stdin);

    printf("Average word length: %.1lf\n", compute_average_word_length(s));

    exit(EXIT_SUCCESS);
}
