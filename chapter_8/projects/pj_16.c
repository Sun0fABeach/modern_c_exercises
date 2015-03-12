#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFSIZE 100

int main() {
    char c, buf[BUFSIZE], *p = buf, letters[26] = {0};

    printf("Enter first word: ");
    fgets(buf, BUFSIZE, stdin);

    while(true) {
        if(isalpha(*p))
            letters[tolower(*p) - 'a']++;
        else if(*p == '\0' || *p == '\n')
            break;
        p++;
    }

    printf("Enter second word: ");
    while((c = getchar()) != '\n')
        if(isalpha(c))
            letters[tolower(c) - 'a']--;

    for(int i = 0; i < 26; i++)
        if(letters[i]) {
            puts("The words are not amagrams.");
            exit(EXIT_SUCCESS);
        }

    puts("The words are amagrams.");

    exit(EXIT_SUCCESS);
}
