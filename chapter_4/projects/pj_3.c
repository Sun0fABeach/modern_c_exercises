#include <stdio.h>

int main() {
  unsigned char d1, d2, d3;

  printf("Enter a three-digit number: ");
  scanf("%1hhu%1hhu%1hhu", &d1, &d2, &d3);
  printf("The reversal is: %d%d%d\n", d3, d2, d1);
}
