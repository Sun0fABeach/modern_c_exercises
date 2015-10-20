#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define OUTFILE_SUFFIX ".enc"

int main() {
    char in_fname_buf[FILENAME_MAX+1];

    printf("enter name of file to be encrypted: ");
    fgets(in_fname_buf, FILENAME_MAX+1, stdin);
    size_t slen = strlen(in_fname_buf);
    if(in_fname_buf[slen-1] == '\n')
        in_fname_buf[slen-1] = '\0';

    size_t suffix_len = strlen(OUTFILE_SUFFIX);
    char out_fname_buf[FILENAME_MAX+1 + suffix_len];
    strcpy(out_fname_buf, in_fname_buf);
    strcat(out_fname_buf, OUTFILE_SUFFIX);

    FILE *infile = fopen(in_fname_buf, "r");
    if(!infile) {
        fprintf(stderr, "could not open file %s\n", in_fname_buf);
        exit(EXIT_FAILURE);
    }
    FILE *outfile = fopen(out_fname_buf, "w");
    if(!outfile) {
        fprintf(stderr, "could not open file %s\n", out_fname_buf);
        fclose(infile);
        exit(EXIT_FAILURE);
    }

    unsigned char shift_amount;
    printf("enter shift amount (1-25): ");
    scanf("%hhu", &shift_amount);

    int ch, check;
    while((ch = fgetc(infile)) != EOF) {
        if(isupper(ch))
            check = putc(((ch - 'A') + shift_amount) % 26 + 'A', outfile);
        else if(islower(ch))
            check = putc(((ch - 'a') + shift_amount) % 26 + 'a', outfile);
        else
            check = putc(ch, outfile);

        if(check == EOF) break;
    }

    bool error_occurred = false;

    if(ferror(infile)) {
        fprintf(stderr, "error while reading %s\n", in_fname_buf);
        error_occurred = true;
    }
    if(ferror(outfile)) {
        fprintf(stderr, "error while writing to %s\n", out_fname_buf);
        error_occurred = true;
    }

    fclose(infile);
    fclose(outfile);

    if(error_occurred) {
        exit(EXIT_FAILURE);
    } else {
        printf("encrypted message successfully written to %s\n", out_fname_buf);
        exit(EXIT_SUCCESS);
    }
}
