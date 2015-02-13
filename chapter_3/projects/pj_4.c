#include <stdio.h>

int main() {
  unsigned short a, b, c;

  printf("Enter phone number [(xxx) xxx-xxxx]: ");
  scanf("(%hu) %hu-%hu", &a, &b, &c);

  printf("You entered: %hu.%hu.%hu\n", a, b, c);

  return 0;
}
