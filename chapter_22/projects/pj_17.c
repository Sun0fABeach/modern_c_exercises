/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* fcopy.c (Chapter 22, page 568) */
/* Copies a file */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    FILE *source_fp;

    if (argc != 2) {
        fprintf(stderr, "usage: pj_17 source\n");
        exit(EXIT_FAILURE);
    }

    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    int ch, i = 0;

    while(true) {
        if((ch = getc(source_fp)) == EOF)
            break;
        if(isdigit(ch)) {
            switch(i % 10) {
                case 0:
                    if(i != 0)
                        putchar('\n');
                    putchar('(');
                    break;
                case 3:
                    printf(") ");
                    break;
                case 6:
                    putchar('-');
                    break;
            }
            putchar(ch);
            ++i;
        }
    }
    putchar('\n');

    bool err_occurred = false;

    if(ferror(source_fp)) {
        fprintf(stderr, "error while reading from %s\n", argv[1]);
        err_occurred = true;
    }

    fclose(source_fp);

    exit(err_occurred ? EXIT_FAILURE : EXIT_SUCCESS);
}
