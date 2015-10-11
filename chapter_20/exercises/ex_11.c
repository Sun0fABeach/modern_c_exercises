#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 4

int main()
{
    char key_code = 0;

    if((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
        puts("No modifier keys pressed");

    exit(EXIT_SUCCESS);
}
