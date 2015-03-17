#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFSIZE 100

void read_word(int counts[26])
{
    char c;
    while((c = getchar()) != '\n')
        if(isalpha(c))
            counts[tolower(c) - 'a']--;
}

bool equal_array(int counts1[26], int counts2[26])
{
    for(int i = 0; i < 26; i++)
        if(counts1[i] != counts2[i])
            return false;
    return true;
}

int main() {
    int counts1[26] = {0}, counts2[26] = {0};

    printf("Enter first word: ");
    read_word(counts1);
    printf("Enter second word: ");
    read_word(counts2);

    printf("The words are %samagrams.\n",
            equal_array(counts1, counts2) ? "" : "not ");

    exit(EXIT_SUCCESS);
}
