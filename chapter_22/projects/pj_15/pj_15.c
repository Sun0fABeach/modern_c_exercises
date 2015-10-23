/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* justify.c (Chapter 15, page 363) */
/* Formats a file of text */

#include <string.h>
#include <stdlib.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(int argc, char *argv[])
{
	if(argc < 3) {
		fputs("usage: pj_15 infile outfile\n", stderr);
		exit(EXIT_FAILURE);
	}

	FILE *const infile = fopen(argv[1], "r");
	if(!infile) {
		fprintf(stderr, "could not open input file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FILE *const outfile = fopen(argv[2], "w");
	if(!outfile) {
		fprintf(stderr, "could not open output file %s\n", argv[2]);
		fclose(infile);
		exit(EXIT_FAILURE);
	}

    char word[MAX_WORD_LEN+2];
    int word_len;

    clear_line();
    for (;;) {
        if(!read_word(word, MAX_WORD_LEN+1, infile)) {
			fprintf(stderr, "error while reading file %s\n", argv[1]);
			break;
        }
        word_len = strlen(word);
        if (word_len == 0) {
            if(!flush_line(outfile))
				fprintf(stderr, "error while writing to file %s\n", argv[2]);
            break;
        }
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            if(!write_line(outfile)) {
				fprintf(stderr, "error while writing to file %s\n", argv[2]);
				break;
            }
            clear_line();
        }
        add_word(word);
    }

    fclose(infile);
    fclose(outfile);

    exit(EXIT_SUCCESS);
}
