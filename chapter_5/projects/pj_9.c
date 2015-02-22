#include <stdio.h>

int main() {
  unsigned char day1, month1, year1, day2, month2, year2;
  unsigned short days1, days2;

  printf("Enter first date (mm/dd/yy): ");
  scanf("%2hhu /%2hhu /%2hhu", &month1, &day1, &year1);
  printf("Enter second date (mm/dd/yy): ");
  scanf("%2hhu /%2hhu /%2hhu", &month2, &day2, &year2);

  days1 = day1 + month1 * 31 + year1 * 365;
  days2 = day2 + month2 * 31 + year2 * 365;

  if(days1 < days2)
    printf("%hhu/%hhu/%hhu is earlier than %hhu/%hhu/%hhu\n",
      month1, day1, year1, month2, day2, year2);
  else
    printf("%hhu/%hhu/%hhu is earlier than %hhu/%hhu/%hhu\n",
      month2, day2, year2, month1, day1, year1);

  return 0;
}
