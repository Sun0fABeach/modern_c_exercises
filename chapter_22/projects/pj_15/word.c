/*********************************************************
 * From C PROGRAMMING: A MODERN APPROACH, Second Edition *
 * By K. N. King                                         *
 * Copyright (c) 2008, 1996 W. W. Norton & Company, Inc. *
 * All rights reserved.                                  *
 * This program may be freely distributed for class use, *
 * provided that this copyright notice is retained.      *
 *********************************************************/

/* word.c (Chapter 15, page 363) */

#include "word.h"

int read_char(FILE *const infile)
{
	int ch = getc(infile);

	if (ch == '\n' || ch == '\t')
		return ' ';
	return ch;
}

bool read_word(char *word, int len, FILE *const infile)
{
	int ch, pos = 0;

	while ((ch = read_char(infile)) == ' ')
		;
	if(ferror(infile))
		return false;

	while (ch != ' ' && ch != EOF) {
		if (pos < len)
		word[pos++] = ch;
		ch = read_char(infile);
	}
	if(ferror(infile))
		return false;

	word[pos] = '\0';

	return true;
}