#include <stdio.h>

int main() {
  for(int i = 1; i <= 128; i <<= 1)
    printf("%d ", i);

  return 0;
}
