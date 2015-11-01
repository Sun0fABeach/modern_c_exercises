#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define OUTFILE_SUFFIX ".win"
#define WIN_EOL "\r\n"
#define WIN_EOF '\x1a'


int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: pj_19a source\n");
        exit(EXIT_FAILURE);
    }

    FILE *source_fp;
    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    size_t suffix_len = strlen(OUTFILE_SUFFIX);
    char out_fname_buf[strlen(argv[1]) + suffix_len + 1];
    strcpy(out_fname_buf, argv[1]);
    strcat(out_fname_buf, OUTFILE_SUFFIX);

    FILE *dest_fp = fopen(out_fname_buf, "wb");
    if(!dest_fp) {
        fprintf(stderr, "can't open %s\n", out_fname_buf);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    int ch;
    while((ch = fgetc(source_fp)) != EOF) {
        if(ch == '\n') {
            if(fwrite(WIN_EOL, sizeof(char), 2, dest_fp) != 2)
                break;
        } else {
            if(putc(ch, dest_fp) == EOF)
                break;
        }
    }

    putc(WIN_EOF, dest_fp);

    bool error_occurred = false;

    if(ferror(source_fp)) {
        fprintf(stderr, "error while reading %s\n", argv[1]);
        error_occurred = true;
    }
    if(ferror(dest_fp)) {
        fprintf(stderr, "error while writing to %s\n", out_fname_buf);
        error_occurred = true;
    }

    fclose(source_fp);
    fclose(dest_fp);

    if(error_occurred) {
        exit(EXIT_FAILURE);
    } else {
        printf("target file successfully written to %s\n", out_fname_buf);
        exit(EXIT_SUCCESS);
    }
}
