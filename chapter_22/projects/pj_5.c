#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define KEY '&'

int main(int argc, char *argv[])
{
    FILE *infile, *outfile;

    if(argc < 3) {
        puts("usage: pj_5 infile outfile");
        exit(EXIT_FAILURE);
    }
    if((infile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((outfile = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[2]);
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    int ch;

    while((ch = getc(infile)) != EOF)
        if(putc(ch ^ KEY, outfile) == EOF)
            break;

    bool error_occurred = false;

    if(ferror(infile)) {
        fprintf(stderr, "error while reading from %s\n", argv[1]);
        error_occurred = true;
    } else if(ferror(outfile)) {
        fprintf(stderr, "error while writing to %s\n", argv[2]);
        error_occurred = true;
    }

    fclose(infile);
    fclose(outfile);

    exit(error_occurred ? EXIT_FAILURE : EXIT_SUCCESS);
}
