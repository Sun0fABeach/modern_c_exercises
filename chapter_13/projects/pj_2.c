#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main()
{
    char reminders[MAX_REMIND][MSG_LEN+3];
    char date_str[3 + 5], msg_str[MSG_LEN+1];
    int i, num_remind = 0;
    unsigned char month, day, hour, minute;

    while(true) {
        if(num_remind == MAX_REMIND) {
            puts("-- No space left --");
            break;
        }

        printf("Enter month/day, time and reminder: ");
        scanf("%2hhu/%2hhu", &month, &day);
        if(!day) break;
        if(day > 31) {
            puts("That's not real day of a month. Try again.");
            continue;
        }
        scanf("%2hhu:%2hhu", &hour, &minute);

        sprintf(date_str, "%5hhu %3hhu %2hhu:%.2hhu", month, day, hour, minute);
        read_line(msg_str, MSG_LEN);

        for(i = 0; i < num_remind; i++)
            if(strcmp(date_str, reminders[i]) < 0)
                break;
        for(int j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], date_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    puts("\nMonth Day  Time Reminder");
    for(int j = 0; j < num_remind; j++)
        printf("%s\n", reminders[j]);

    exit(EXIT_SUCCESS);
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
        if(i < n - 1)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}
