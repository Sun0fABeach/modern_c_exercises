#include <stdlib.h>
#include <stdio.h>

int main()
{
  int height = 8, length = 12, width = 10;
  int volume = height * length * width;

  printf("Dimensions: %dx%dx%d\n", length, width, height);
  printf("Volume (cubic inches): %d\n", volume);
  printf("Dimensional weigth (pounds): %d\n", (volume + 165) / 166);

	exit(EXIT_SUCCESS);
}
