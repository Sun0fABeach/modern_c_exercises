#include <stdio.h>

int main() {
  unsigned char day, month;
  unsigned short year;

  printf("Enter a date (mm/dd/yyyy): ");
  scanf("%hhu /%hhu /%hu", &month, &day, &year);

  printf("You entered the date %.4hu%.2hhu%.2hu\n", year, month, day);

  return 0;
}
