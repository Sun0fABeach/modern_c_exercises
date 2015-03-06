#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    unsigned short v_count = 0;

    printf("Enter a sentence: ");
    while((c = getchar()) != '\n')
        switch(toupper(c)) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
                v_count++;
        }

    printf("Your sentence contains %hu vowels.\n", v_count);

    return 0;
}
