#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool is_pali(const char *buff, int n)
{
    const char *right = buff + n - 1;

    while(true) {
        if(buff >= right)
            return true;
        while(!isalpha(*buff))
            if(buff++ == right)
                return true;
        while(!isalpha(*right))
            if(right-- == buff)
                return true;
        if(toupper(*right--) != toupper(*buff++))
            return false;
    }
}

int main()
{
    char buff[20], *right = buff;

    printf("Enter a message: ");
    while(right < buff + 20) {
        if((*right = getchar()) == '\n')
            break;
        right++;
    }
    printf("%salindrome\n", is_pali(buff, right - buff) ? "P" : "Not a p");

    exit(EXIT_SUCCESS);
}
