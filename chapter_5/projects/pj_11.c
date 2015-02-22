#include <stdio.h>

int main() {
  unsigned char num1, num2;

  printf("Enter a two-digit number: ");
  scanf("%1hhu%1hhu", &num1, &num2);

  printf("You entered the number: ");

  if(num1 == 1) {
    switch(num2) {
      case 0: puts("ten"); break;
      case 1: puts("eleven"); break;
      case 2: puts("twelve"); break;
      case 3: puts("thirteen"); break;
      case 4: puts("fourteen"); break;
      case 5: puts("fifteen"); break;
      case 6: puts("sixteen"); break;
      case 7: puts("seventeen"); break;
      case 8: puts("eighteen"); break;
      case 9: puts("nineteen"); break;
    }
  } else {
    switch(num1) {
      case 2: printf("twenty"); break;
      case 3: printf("thirty"); break;
      case 4: printf("fourty"); break;
      case 5: printf("fifty"); break;
      case 6: printf("sixty"); break;
      case 7: printf("seventy"); break;
      case 8: printf("eighty"); break;
      case 9: printf("ninety"); break;
    }
    if(num1 && num2) putchar('-');
    switch(num2) {
      case 0: puts(num1 ? "" : "zero"); break;
      case 1: puts("one"); break;
      case 2: puts("two"); break;
      case 3: puts("three"); break;
      case 4: puts("four"); break;
      case 5: puts("five"); break;
      case 6: puts("six"); break;
      case 7: puts("seven"); break;
      case 8: puts("eight"); break;
      case 9: puts("nine"); break;
    }
  }

  return 0;
}
