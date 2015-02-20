#include <stdio.h>
#include <stdbool.h>

int main() {
  unsigned char age = 16;
  bool teenager = age >= 13 || age <= 19 ? true : false;

  printf("Teenager?: %hhu\n", teenager);

  return 0;
}
