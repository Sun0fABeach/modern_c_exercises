#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char *argv[])
{
    FILE *infile, *outfile;

    if(argc < 2) {
        puts("usage: pj_7a filename");
        exit(EXIT_FAILURE);
    }
    if((infile = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char outname[strlen(argv[1]) + 5];
    strcpy(outname, argv[1]);
    strcat(outname, ".rle");

    if((outfile = fopen(outname, "wb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", outname);
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    unsigned char count = 1;
    int old_c, new_c;

    if((old_c = getc(infile)) == EOF)   // do first read
        goto end;

    while(true) {
        if((new_c = getc(infile)) == EOF) {
            if(putc(count, outfile) == EOF)
                break;
            putc(old_c, outfile);
            break;
        }

        if(new_c == old_c) {
            count++;
        } else {
            if(putc(count, outfile) == EOF)
                break;
            if(putc(old_c, outfile) == EOF)
                break;
            old_c = new_c;
            count = 1;
        }
    }

    end:{}
    bool error_occurred = false;

    if(ferror(infile)) {
        fprintf(stderr, "error while reading from %s\n", argv[1]);
        error_occurred = true;
    }
    if(ferror(outfile)) {
        fprintf(stderr, "error while writing to %s\n", outname);
        error_occurred = true;
    }

    fclose(infile);
    fclose(outfile);

    exit(error_occurred ? EXIT_FAILURE : EXIT_SUCCESS);
}
