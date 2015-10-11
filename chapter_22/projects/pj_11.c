#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
    if(argc < 2) {
        puts("Usage: pj_11 <datestring>");
        exit(EXIT_FAILURE);
    }

    const char *months[] = { "",
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };

    unsigned char month, day;
    unsigned short year;

    if(sscanf(argv[1], "%2hhu-%2hhu-%4hu", &month, &day, &year) != 3) {
        if(sscanf(argv[1], "%2hhu/%2hhu/%4hu", &month, &day, &year) != 3) {
            puts("Bad date format");
            exit(EXIT_FAILURE);
        }
    }

    if(month < 1 || month > 12 || day < 1 || day > 31) {
        puts("Illegal date values");
        exit(EXIT_FAILURE);
    }

    printf("%s %hhu, %hu\n", months[month], day, year);

    exit(EXIT_SUCCESS);
}
