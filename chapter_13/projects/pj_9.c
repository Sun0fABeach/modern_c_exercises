#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned short compute_vowel_count(const char *sentence)
{
    unsigned short v_count = 0;

    while(*sentence)
        switch(toupper(*sentence++)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                v_count++;
        }

    return v_count;
}


int main()
{
    char s[100];

    printf("Enter a sentence: ");
    fgets(s, 100, stdin);

    printf("Your sentence contains %hu vowels.\n", compute_vowel_count(s));

    exit(EXIT_SUCCESS);
}
