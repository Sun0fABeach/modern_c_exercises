#include <stdio.h>
#include <stdlib.h>


int main()
{
    const char *months[12] = {
        "January", "February", "March", "April", "May", "June", "July",
        "August", "September", "October", "November", "December"
    };
    unsigned char month, day;
    unsigned short year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%2hhu /%2hhu /%4hu", &month, &day, &year);

    printf("You entered date %s %hhu, %hu\n", months[month-1], day, year);

    exit(EXIT_SUCCESS);
}
