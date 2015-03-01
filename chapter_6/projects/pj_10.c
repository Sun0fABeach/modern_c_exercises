#include <stdio.h>
#include <stdbool.h>

int main() {
    unsigned char day, month, year, new_day, new_month, new_year;
    unsigned short days, new_days;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%2hhu /%2hhu /%2hhu", &month, &day, &year);

    days = day + month * 31 + year * 365;
    if(!days) return 0;

    while(true) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%2hhu /%2hhu /%2hhu", &new_month, &new_day, &new_year);

        new_days = new_day + new_month * 31 + new_year * 365;

        if(!new_days) break;

        if(new_days < days) {
            day = new_day;
            month = new_month;
            year = new_year;
        }
    }

    printf("%hhu/%hhu/%.2hhu is the earliest date\n", month, day, year);

    return 0;
}
