#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_extension(const char *file_name, char *extension)
{
    char *period = strchr(file_name, '.');
    if(period)
        strcpy(extension, period+1);
    else
        *extension = '\0';
}

int main()
{
    char extension[10];

    const char *file1 = "lala.txt";
    get_extension(file1, extension);
    printf("extension of file %s: %s\n", file1, extension);

    const char *file2 = "lalatxt";
    get_extension(file2, extension);
    printf("extension of file %s: %s\n", file2, extension);

    const char *file3 = "lalatxt.";
    get_extension(file3, extension);
    printf("extension of file %s: %s\n", file3, extension);

    exit(EXIT_SUCCESS);
}
