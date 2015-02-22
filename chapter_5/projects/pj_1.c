#include <stdio.h>

int main() {
  short num;
  unsigned char count = 0;

  printf("Enter a max-four-digit number: ");
  scanf("%hd", &num);

  if(num < 0) num = -num;
  if(num > 9999) num = 9999;

  printf("The number %hd has ", num);

  if(num) count++;
  num /= 10;
  if(num) count++;
  num /= 10;
  if(num) count++;
  num /= 10;
  if(num) count++;

  printf("%hhu digit%s\n", count, count > 1 ? "s" : "");

  return 0;
}
