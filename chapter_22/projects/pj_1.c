/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* canopen.c (Chapter 22, page 547) */
/* Checks whether a file can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if(argc < 2) {
        puts("usage: pj_1 filename1 [, filename2, ...]");
        exit(EXIT_FAILURE);
    }

    while(--argc) {
        if((fp = fopen(argv[argc], "r")) == NULL) {
            printf("%s can't be opened\n", argv[argc]);
        } else {
            printf("%s can be opened\n", argv[argc]);
            fclose(fp);
        }
    }

    exit(EXIT_SUCCESS);
}
