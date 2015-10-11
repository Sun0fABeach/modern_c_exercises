#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc < 2) {
        puts("Usage: pj_12 <filename>");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if((fp = fopen(argv[1], "r")) == NULL) {
        fputs("Unable to open file\n", stderr);
        exit(EXIT_FAILURE);
    }

    unsigned int item;
    float price;
    char *date;

    printf("%-10s%-10s%-10s\n", "Item", "Unit", "Purchase");
    printf("%-10s%-10s%-10s\n", "", "Price", "Date");

    while(fscanf(fp, "%u, %f, %m[0-9/]", &item, &price, &date) == 3) {
        printf("%-9u $ %-7.2f %s\n", item, price, date);
        free(date);
    }

    if(ferror(fp)) {
        fputs("An error occured while reading file\n", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    exit(EXIT_SUCCESS);
}
