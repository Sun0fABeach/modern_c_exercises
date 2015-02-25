#include <stdio.h>

int main() {
  for(int i = 0; i <= 10; i++) {
    if(i % 2) continue;
    printf("%d ", i);
  }

  putchar('\n');

  for(int i = 0; i <= 10; i++) {
    if(i % 2) goto skipped;
    printf("%d ", i);
    skipped:;
  }

  return 0;
}
