#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60

int main()
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char day_str[3], msg_str[MSG_LEN+1];
    int day, i, num_remind = 0;

    while(true) {
        if(num_remind == MAX_REMIND) {
            puts("-- No space left --");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if(day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++)
            if(strcmp(day_str, reminders[i]) < 0)
                break;
        for(int j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    puts("\nDay Reminder");
    for(int j = 0; j < num_remind; j++)
        printf(" %s\n", reminders[j]);

    exit(EXIT_SUCCESS);
}
