#include <stdio.h>
#include <math.h>

int main() {
  int r = 10;

  float v = 4.0f / 3 * M_PI * pow(r, 3);
  printf("%f\n", v);

  return 0;
}
