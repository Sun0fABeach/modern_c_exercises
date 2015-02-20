#include <stdio.h>
#include <stdbool.h>

int main() {
  unsigned short area_code = 478;

  switch(area_code) {
    case 229: puts("Albany"); break;
    case 404: puts("Atlanta"); break;
    case 470: puts("Atlanta"); break;
    case 478: puts("Macon"); break;
    case 678: puts("Atlanta"); break;
    case 706: puts("Columbus"); break;
    case 762: puts("Columbus"); break;
    case 770: puts("Atlanta"); break;
    case 912: puts("Savannah"); break;
    default: puts("Area code not recognized");
  }

  return 0;
}
