#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

unsigned short compute_scrabble_value(const char *word)
{
    unsigned short sum = 0;

    while(*word)
        switch(toupper(*word++)) {
            case 'A': case 'E': case 'I': case 'L': case 'N':
            case 'O': case 'R': case 'S': case 'T': case 'U':
                sum += 1; break;
            case 'D': case 'G':
                sum += 2; break;
            case 'B': case 'C': case 'M': case 'P':
                sum += 3; break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                sum += 4; break;
            case 'K':
                sum += 5; break;
            case 'J': case 'X':
                sum += 8; break;
            case 'Q': case 'Z':
                sum += 10; break;
        }

    return sum;
}

int main()
{
    char s[100];

    printf("Enter a word: ");
    fgets(s, 100, stdin);

    printf("Scrabble value: %hu\n", compute_scrabble_value(s));

    exit(EXIT_SUCCESS);
}
