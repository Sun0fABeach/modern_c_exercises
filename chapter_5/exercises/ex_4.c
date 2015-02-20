#include <stdio.h>

int main() {
  char i = -1, j = 1;
  printf("%hhd\n", i < j ? -1 : i > j ? 1 : 0);

  i = 0; j = 0;
  printf("%hhd\n", i < j ? -1 : i > j ? 1 : 0);

  i = 1; j = -1;
  printf("%hhd\n", i < j ? -1 : i > j ? 1 : 0);

  return 0;
}
