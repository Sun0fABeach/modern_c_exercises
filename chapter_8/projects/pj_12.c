#include <stdio.h>
#include <ctype.h>

int main() {
    char c, values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3,
                          10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    unsigned short sum = 0;

    printf("Enter a word: ");
    while((c = getchar()) != '\n')
        sum += values[toupper(c) - 'A'];
    printf("Scrabble value: %hu\n", sum);

    return 0;
}
