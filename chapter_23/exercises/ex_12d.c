#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define SWAP(a, b) ((a) ^= (b), (b) ^= (a), (a) ^= (b))

char *strrev(char *s)
{
    if(*s == '\0')
        return s;

    char *front = s;
    char *back = front;

    while(*back) {
        ++back;
    }
    --back;

    while(front < back) {
        SWAP(*front, *back);
        ++front;
        --back;
    }
    return s;
}

int main()
{
    char s1[] = "123";
    puts(strrev(s1));

    char s2[] = "12";
    puts(strrev(s2));

    char s3[] = "";
    puts(strrev(s3));

    exit(EXIT_SUCCESS);
}
