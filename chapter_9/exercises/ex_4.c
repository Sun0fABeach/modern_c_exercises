#include <stdio.h>
#include <stdlib.h>

int day_of_year(int month, int day, int year);

int main() {
    int month, day, year;

    printf("Enter month, day, year: ");
    scanf("%d%d%d", &month, &day, &year);

    printf("Day of the year: %d\n", day_of_year(month, day, year));

    exit(EXIT_SUCCESS);
}

int day_of_year(int month, int day, int year)
{
    int result = 0;
    for(int i = 1; i < month; i++)
        switch(i) {
            case 1: case 3: case 5: case 7: case 8: case 10:
                result += 31;
                break;
            case 4: case 6: case 9: case 11:
                result += 30;
                break;
            case 2:
                result += year % 4 ? 28 : 29;
        }

    return result + day;
}
