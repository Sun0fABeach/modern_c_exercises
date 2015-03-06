#include <stdio.h>
#include <ctype.h>

int main() {
    char c, initial;

    printf("Enter a first and last name: ");

    scanf(" %c", &initial);
    scanf("%*[^ \t\n] ");
    while(isalpha(c = getchar()))
        putchar(c);
    printf(", %c.\n", initial);

    return 0;
}
