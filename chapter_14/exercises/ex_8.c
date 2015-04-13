#include <stdio.h>
#include <stdlib.h>

#define PRESTR(x) STR(x)
#define STR(x) #x
#define LINE_FILE "Line "PRESTR(__LINE__)" of file "__FILE__

int main()
{
    const char *s = LINE_FILE;
    puts(s);

    exit(EXIT_SUCCESS);
}
