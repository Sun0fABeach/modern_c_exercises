#include <stdio.h>
#include <stdbool.h>

int main() {
    char a[100], *p = a;

    printf("Enter a message: ");
    while((*p++ = getchar()) != '\n')
        ;

    printf("In B1FF-speak: ");
    p = a;
    while(true) {
        switch(*p) {
            case 'A': putchar('4'); break;
            case 'B': putchar('8'); break;
            case 'E': putchar('3'); break;
            case 'I': putchar('1'); break;
            case 'O': putchar('0'); break;
            case 'S': putchar('5'); break;
            case '\n':
                puts("!!!!!!!!!!");
                goto endloop;
            default: putchar(*p);
        }
        p++;
    };

    endloop:
    return 0;
}
