#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFSIZE 80

int main() {
    char buf[BUFSIZE];
    unsigned char shift_amount;

    printf("Enter message to be encrypted: ");
    fgets(buf, BUFSIZE, stdin);
    printf("Enter shift amount (1-25): ");
    scanf("%hhu", &shift_amount);
    printf("Encrypted message: ");

    for(int i = 0; i < BUFSIZE; i++)
        if(buf[i] == '\0' || buf[i] == '\n')
            break;
        else if(isupper(buf[i]))
            putchar(((buf[i] - 'A') + shift_amount) % 26 + 'A');
        else if(islower(buf[i]))
            putchar(((buf[i] - 'a') + shift_amount) % 26 + 'a');
        else putchar(buf[i]);

    putchar('\n');

    return 0;
}
