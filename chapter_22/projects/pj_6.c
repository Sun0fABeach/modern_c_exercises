#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define BYTES_PER_LINE 10

int main(int argc, char *argv[])
{
    FILE *fp;

    if(argc < 2) {
        puts("usage: pj_6 filename");
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%6s%14s%-19s%s\n", "Offset", "", "Bytes", "Characters");
    printf("------  ");
    for(size_t i = 0; i < BYTES_PER_LINE * 3 - 1; i++)
        putchar('-');
    printf("  ----------\n");

    char buf[BYTES_PER_LINE];

    for(size_t offset = 0; ; offset += BYTES_PER_LINE) {
        size_t col;
        size_t num_read = fread(buf, 1, BYTES_PER_LINE, fp);

        printf("%6zu  ", offset);               //offset
        for(col = 0; col < num_read; col++)     //bytes in hex
            printf("%2hhX ", buf[col]);
        putchar(' ');
        while(col++ < BYTES_PER_LINE)           //spaces when last line
            printf("   ");
        for(col = 0; col < num_read; col++)     //bytes as chars
            printf("%c", isprint(buf[col]) ? buf[col] : '.');
        putchar('\n');
        if(num_read != BYTES_PER_LINE)
            break;
    }

    if(ferror(fp))
        fprintf(stderr, "error while reading from %s\n", argv[1]);

    fclose(fp);

    exit(EXIT_SUCCESS);
}
