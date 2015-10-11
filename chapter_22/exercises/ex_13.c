#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


int line_length(const char *filename, int n)
{
    int ch, length = 0;
    FILE *fp;

    if(n <= 0) return 0;

    if((fp = fopen(filename, "r"))) {
        while(--n) { // skip them lines
            while(true) {
                if((ch = getc(fp)) == '\n') break;
                if(ch == EOF) {
                    if(ferror(fp)) {
                        fputs("Error while reading file", stderr);
                        fclose(fp);
                    }
                    return 0;
                }
            }
        }
        while(true) { // count line_length
            if((ch = getc(fp)) == '\n' || ch == EOF)
                break;
            length++;
        }

        if(ferror(fp))
            fputs("Error while reading the line", stderr);
        fclose(fp);
        return length;

    } else {
        fprintf(stderr, "Could not open file %s\n", filename);
        return 0;
    }

}


int main(int argc, char *argv[])
{
    char filename[FILENAME_MAX+1];
    int lineno;

    if(strlen(*argv) > FILENAME_MAX-2) {
        fputs("WTF?\n", stderr);
        exit(EXIT_FAILURE);
    }

    strcpy(filename, *argv);
    strcat(filename, ".c");

    printf("Enter number of line of which to count characters: ");
    if(!scanf("%d", &lineno)) {
        fputs("Can't handle that shit!\n", stderr);
        exit(EXIT_FAILURE);
    }

    printf(
        "Line %d of this source code has %d characters\n",
        lineno, line_length(filename, lineno)
    );

    exit(EXIT_SUCCESS);
}
