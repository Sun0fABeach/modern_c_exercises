#include <stdio.h>

int main() {
  unsigned char hour, minute;

  printf("Enter a 24-hour time: ");
  scanf("%2hhu :%2hhu", &hour, &minute);

  if(hour == 24)      hour = 0;
  else if(hour > 12)  hour -= 12;

  printf("Equivalent 12-hour time: %2hhu:%.2hhu\n", hour, minute);

  return 0;
}
