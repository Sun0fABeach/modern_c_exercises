#include <stdio.h>

int main() {
  unsigned char x;

  printf("Enter a two-digit number: ");
  scanf("%hhu", &x);
  printf("The reversal is: %d%d\n", x%10, x/10);
}
