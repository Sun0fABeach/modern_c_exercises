#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


bool is_palindrome(const char *message)
{
    const char *left = message, *right = message;

    while(*right)
        right++;
    right--;

    while(true) {
        if(left >= right)
            return true;
        while(!isalpha(*left))
            if(++left == right)
                return true;
        while(!isalpha(*right))
            if(--right == left)
                return true;
        if(toupper(*left++) != toupper(*right--))
            return false;
    }
}


int main()
{
    char buff[20];
    int i;

    printf("Enter a message: ");
    for(i = 0; i < 19; i++)
        if((buff[i] = getchar()) == '\n')
            break;
    buff[i] = '\0';

    printf("%salindrome\n", is_palindrome(buff) ? "P" : "Not a p");

    exit(EXIT_SUCCESS);
}
