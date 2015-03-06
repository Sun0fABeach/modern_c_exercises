#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    unsigned short count = 0, sum = 0;
    char c;
    bool in_word = false;

    printf("Enter a sentence: ");

    while((c = getchar()) != '\n') {
        if(in_word)
            if(isspace(c))
                in_word = false;
            else
                sum++;
        else
            if(!isspace(c)) {
                in_word = true;
                count++;
                sum++;
            }
    }

    printf("Average word length: %.1lf\n", (double) sum / count);

    return 0;
}
