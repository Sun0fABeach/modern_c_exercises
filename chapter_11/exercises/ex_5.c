#include <stdio.h>
#include <stdlib.h>

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / (60 * 60);
    total_sec %= 60 * 60;
    *min = total_sec / 60;
    *sec = total_sec % 60;
}

int main()
{
    int hr, min, sec;

    split_time(60 * 60 * 11 + 60 * 7 + 35, &hr, &min, &sec);    //11:07:35
    printf("Hours: %d, minutes: %d, seconds: %d\n", hr, min, sec);

    exit(EXIT_SUCCESS);
}
