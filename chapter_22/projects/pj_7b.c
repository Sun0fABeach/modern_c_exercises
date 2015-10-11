#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SUFFIX ".rle"


int main(int argc, char *argv[])
{
    FILE *infile, *outfile;

    if(argc < 2) {
        puts("usage: pj_7b filename");
        exit(EXIT_FAILURE);
    }

    size_t fname_len = strlen(argv[1]);
    size_t suffix_len = strlen(SUFFIX);
    size_t fname_len_no_suffix = fname_len - suffix_len;

    if(fname_len <= suffix_len ||
            strcmp(argv[1] + fname_len_no_suffix, SUFFIX)) {
        fputs("File to decode needs to have suffix '.rle'", stderr);
        exit(EXIT_FAILURE);
    }

    char outname[fname_len_no_suffix + 1];
    strncpy(outname, argv[1], fname_len_no_suffix);
    outname[fname_len_no_suffix] = '\0';

    if((infile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if((outfile = fopen(outname, "wb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", outname);
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    while(true) {
        int count, value;
        if((count = getc(infile)) == EOF)
            break;
        if((value = getc(infile)) == EOF)
            break;

        while(count--)
            if(putc(value, outfile) == EOF)
                break;
    }

    bool error_occurred = false;

    if(ferror(infile)) {
        fprintf(stderr, "error while reading from %s\n", argv[1]);
        error_occurred = true;
    } else if(ferror(outfile)) {
        fprintf(stderr, "error while writing to %s\n", outname);
        error_occurred = true;
    }

    fclose(infile);
    fclose(outfile);

    exit(error_occurred ? EXIT_FAILURE : EXIT_SUCCESS);
}
