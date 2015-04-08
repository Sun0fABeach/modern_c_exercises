#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFSIZE 80

void encrypt(char *message, int shift)
{
    while(*message) {
        if(*message == '\n')
            break;
        if(isupper(*message))
            *message = (*message - 'A' + shift) % 26 + 'A';
        else if(islower(*message))
            *message = (*message - 'a' + shift) % 26 + 'a';
        message++;
    }
}

int main()
{
    char buf[BUFSIZE];
    unsigned char shift_amount;

    printf("Enter message to be encrypted: ");
    fgets(buf, BUFSIZE, stdin);
    printf("Enter shift amount (1-25): ");
    scanf("%hhu", &shift_amount);
    encrypt(buf, shift_amount);
    printf("Encrypted message: %s\n", buf);

    exit(EXIT_SUCCESS);
}
