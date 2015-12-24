#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int count_words(char *sentence)
{
    const char *delimiters = " \n\t";
    int count;

    if(strtok(sentence, delimiters))
        count = 1;
    else
        return 0;

    while(strtok(NULL, delimiters))
        ++count;

    return count;
}

int main()
{
    char s1[] = "abc\n";
    printf("%-15s: %d\n",  "abc\\n", count_words(s1));

    char s2[] = "a b,.b\nc";
    printf("%-15s: %d\n",  "a b,.b\\nc", count_words(s2));

    char s3[] = "  asd\tasd  ";
    printf("%-15s: %d\n",  "  asd\\tasd  ", count_words(s3));

    char s4[] = "";
    printf("%-15s: %d\n", "", count_words(s4));

    char s5[] = " \n\t";
    printf("%-15s: %d\n", " \\n\\t", count_words(s5));

    exit(EXIT_SUCCESS);
}
