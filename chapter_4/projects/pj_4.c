#include <stdio.h>

int main() {
  unsigned short num;
  unsigned char d1, d2, d3, d4, d5;

  printf("Enter a number between 0 and 32767: ");
  scanf("%hu", &num);
  if(num > 32767)
    num = 32767;

  d1 = num % 8;
  num /= 8;
  d2 = num % 8;
  num /= 8;
  d3 = num % 8;
  num /= 8;
  d4 = num % 8;
  num /= 8;
  d5 = num % 8;

  printf("In octal, your number is: %hhu%hhu%hhu%hhu%hhu\n",
      d5, d4, d3, d2, d1);
}
