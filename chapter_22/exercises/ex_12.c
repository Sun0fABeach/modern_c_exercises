#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    char c;

    if((fp = fopen(filename, "r")) != NULL) {
        while((c = fgetc(fp)) != EOF)
            if(c == '.') n++;
        if(ferror(fp))
            fputs("Error while reading source file!\n", stderr);
        fclose(fp);
    }

    return n;
}

int main(int argc, char *argv[])
{
    char filename[FILENAME_MAX];

    if(strlen(*argv) > FILENAME_MAX-3) {
        fputs("WTF?\n", stderr);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, *argv);
    strcat(filename, ".c");

    printf("This source code contains %d periods\n", count_periods(filename));

    exit(EXIT_SUCCESS);
}
