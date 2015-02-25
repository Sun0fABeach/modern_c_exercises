#include <stdio.h>
#include <stdbool.h>

int main() {
  float n, largest = 0.0f;
  bool useful_input = false;

  do {
    printf("Enter a number: ");
    scanf("%f", &n);

    if(n > largest) {
      useful_input = true;
      largest = n;
    }
  } while(n > 0.0f);

  if(useful_input)
    printf("The largest number entered was %.2f\n", largest);

  return 0;
}
