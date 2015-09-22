#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


char *my_fgets(char *str, int num, FILE *stream)
{
    if(num <= 1) {  // no room for anything
        if(num) *str = '\0';
        return str;
    }

    int ch;         // end of stream already reached
    if((ch = getc(stream)) == EOF)
        return NULL;

    int i = 0;
    do {
        str[i++] = ch;
        if(ch == '\n')
            break;
        if((ch = getc(stream)) == EOF) {
            if(ferror(stream))
                return NULL;
            break;
        }
    } while(i < num-1);

    str[i] = '\0';

    return str;
}


int my_fputs(const char *str, FILE *stream)
{
    while(*str)
        if(putc(*str++, stream) == EOF && ferror(stream))
            return -1;
    return 0;
}


int main()
{
    #define NUM_CHARS 10
    char str[NUM_CHARS+1];

    printf("Type something (max %d chars): ", NUM_CHARS);
    my_fgets(str, NUM_CHARS+1, stdin);
    printf("You typed: |");
    my_fputs(str, stdout);
    puts("|");

    exit(EXIT_SUCCESS);
}
