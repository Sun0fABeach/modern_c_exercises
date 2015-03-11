#include <stdio.h>
#include <ctype.h>

int main() {
    char a[15];

    printf("Enter a phone number: ");
    for(int i = 0; i < 15; i++)
        if((a[i] = getchar()) == '\n')
            break;

    printf("In numeric form: ");
    for(int i = 0; i < 15; i++)
        if(isupper(a[i]))
            switch(a[i]) {
                case 'A': case 'B': case 'C':
                    putchar('2'); break;
                case 'D': case 'E': case 'F':
                    putchar('3'); break;
                case 'G': case 'H': case 'I':
                    putchar('4'); break;
                case 'J': case 'K': case 'L':
                    putchar('5'); break;
                case 'M': case 'N': case 'O':
                    putchar('6'); break;
                case 'P': case 'R': case 'S':
                    putchar('7'); break;
                case 'T': case 'U': case 'V':
                    putchar('8'); break;
                case 'W': case 'X': case 'Y':
                    putchar('9'); break;
            }
        else if(putchar(a[i]) == '\n')
            break;

    return 0;
}
