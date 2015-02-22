#include <stdio.h>

int main() {
  unsigned char knots;
  const char *description;

  printf("Enter the wind speed in knots: ");
  scanf("%hhu", &knots);

  if(knots < 1)       description = "Calm";
  else if(knots < 4)  description = "Light air";
  else if(knots < 28) description = "Breeze";
  else if(knots < 48) description = "Gale";
  else if(knots < 64) description = "Storm";
  else                description = "Hurricane";

  printf("Description on the Beaufort scale: %s\n", description);

  return 0;
}
