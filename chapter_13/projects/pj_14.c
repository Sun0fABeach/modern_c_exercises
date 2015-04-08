#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFSIZE 100

bool are_anagrams(const char *word1, const char *word2)
{
    char letters[26] = {0};

    while(*word1) {
        if(isalpha(*word1))
            letters[tolower(*word1) - 'a']++;
        word1++;
    }
    while(*word2) {
        if(isalpha(*word2))
            letters[tolower(*word2) - 'a']--;
        word2++;
    }
    for(int i = 0; i < 26; i++)
        if(letters[i]) return false;
    return true;
}

int main() {
    char word1[BUFSIZE], word2[BUFSIZE];

    printf("Enter first word: ");
    fgets(word1, BUFSIZE, stdin);
    printf("Enter second word: ");
    fgets(word2, BUFSIZE, stdin);

    printf("The words are %sanagrams.\n",
            are_anagrams(word1, word2) ? "" : "not ");

    exit(EXIT_SUCCESS);
}
