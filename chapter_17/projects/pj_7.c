#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */


typedef struct {
    int len;
    char chars[];
} Vstring;

int read_line(char str[], int n);

int main(void)
{
  Vstring *reminders[MAX_REMIND];
  char day_str[3], msg_str[MSG_LEN+1];
  int day, i, len, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    sprintf(day_str, "%2d", day);
    len = read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]->chars) < 0)
        break;
    for (int j = num_remind; j > i; j--)
      reminders[j] = reminders[j-1];

    reminders[i] = malloc( sizeof(Vstring) + ((2 + len + 1) * sizeof(char)) );
    if (reminders[i] == NULL) {
      printf("-- No space left --\n");
      break;
    }

    reminders[i]->len = len;
    strcpy(reminders[i]->chars, day_str);
    strcat(reminders[i]->chars, msg_str);

    num_remind++;
  }

  printf("\nDay Reminder\n");
  for (i = 0; i < num_remind; i++) {
    printf(" %s\n", reminders[i]->chars);
    free(reminders[i]);
  }

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
