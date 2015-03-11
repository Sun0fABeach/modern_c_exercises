#include <stdio.h>
#include <ctype.h>

int main() {
    char initial, buf[20];
    int i;

    printf("Enter a first and last name: ");
    scanf(" ");
    for(i = 0; i < 20; i++)
        if((buf[i] = getchar()) == '\n')
            break;

    printf("You entered the name: ");
    sscanf(buf, " %c%*[^ \t\n] %n", &initial, &i);
    while(i < 20 && buf[i] != '\n')
        putchar(buf[i++]);
    printf(", %c.\n", toupper(initial));

    return 0;
}
