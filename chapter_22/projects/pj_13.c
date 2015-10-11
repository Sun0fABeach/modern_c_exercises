#include <stdio.h>
#include <stdlib.h>

#define MAX_TIMES 10

int main() {
    FILE *fp;
    const char *fname = "flights.dat";

    if((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open file %s\n", fname);
        exit(EXIT_FAILURE);
    }

    struct {
        char departure[6];
        char arrival[6];
        unsigned short dep_in_minutes;
    } times[MAX_TIMES];
    int ntimes;
    unsigned char hour, minutes;

    puts("Flight table:");
    for(ntimes = 0; ntimes < MAX_TIMES; ntimes++) {
        if(fscanf(
            fp, "%5s %5s", times[ntimes].departure, times[ntimes].arrival
        ) != 2) {
            if(ferror(fp)) {
                fprintf(stderr, "Error while reading file %s\n", fname);
                fclose(fp);
                exit(EXIT_FAILURE);
            } else break;
        }
        sscanf(times[ntimes].departure, "%hhu:%hhu", &hour, &minutes);
        times[ntimes].dep_in_minutes = hour * 60 + minutes;
        printf("%s %s\n", times[ntimes].departure, times[ntimes].arrival);
    }
    fclose(fp);

    printf("Enter a 24-hour time: ");
    scanf("%2hhu :%2hhu", &hour, &minutes);
    unsigned short full_minutes = hour * 60 + minutes;

    for(int i = 0; i < ntimes-1; i++) {
        short prev_diff = full_minutes - times[i].dep_in_minutes;
        if(prev_diff < 0) prev_diff = -prev_diff;

        short new_diff = full_minutes - times[i+1].dep_in_minutes;
        if(new_diff < 0) new_diff = -new_diff;

        if(prev_diff < new_diff) {
            printf("Closest departure time is %s, arriving at %s.\n",
                times[i].departure, times[i].arrival);
            exit(EXIT_SUCCESS);
        }
    }

    printf("Closest departure time is %s, arriving at %s.\n",
        times[ntimes-1].departure, times[ntimes-1].arrival);
    exit(EXIT_SUCCESS);
}
