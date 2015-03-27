#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    char buff[20], *left = buff, *right = buff;

    printf("Enter a message: ");
    while(right < buff + 20) {
        if((*right = getchar()) == '\n')
            break;
        right++;
    }
    right--;

    while(true) {
        if(left >= right)
            break;
        while(!isalpha(*left))
            if(left++ == right)
                break;
        while(!isalpha(*right))
            if(right-- == left)
                break;
        if(toupper(*right--) != toupper(*left++)) {
            puts("Not a palindrome");
            exit(EXIT_SUCCESS);
        }
    }
    puts("Palindrome");

    exit(EXIT_SUCCESS);
}
