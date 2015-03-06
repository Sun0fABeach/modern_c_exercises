#include <stdio.h>
#include <ctype.h>

int main() {
    unsigned char hour, minutes;
    char daytime;
    unsigned short full_minutes;
    short prev_diff, new_diff;

    printf("Enter a 12-hour time: ");
    scanf("%2hhu :%2hhu %c", &hour, &minutes, &daytime);

    if(tolower(daytime) == 'p')
        hour += 12;
    full_minutes = hour * 60 + minutes;

    prev_diff = full_minutes - 480; //8:00
    if(prev_diff < 0) prev_diff = -prev_diff;

    new_diff = full_minutes - 583; //9:43
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 679; //11:19
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 767; //12:47
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 840; //14:00
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 945; //15:45
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 1140; //19:00
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff) {
        puts("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.");
        return 0;
    }

    prev_diff = new_diff;
    new_diff = full_minutes - 1305; //21:45
    if(new_diff < 0) new_diff = -new_diff;

    if(prev_diff < new_diff)
        puts("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.");
    else
        puts("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.");

    return 0;
}
