#include <stdio.h>

int main() {
  unsigned short x;

  printf("Enter a three-digit number: ");
  scanf("%hu", &x);
  printf("The reversal is: %d%d%d\n", x%10, x%100/10, x/100);
}
