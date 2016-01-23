#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>


int main()
{
    printf("Current locale: %s\n", setlocale(LC_ALL, NULL));

    const char *def_loc = setlocale(LC_ALL, "");
    const char *c_loc = setlocale(LC_ALL, "C");

    printf("Default locale: %s\n", def_loc);
    printf("C locale: %s\n", c_loc);

    puts(!strcmp(def_loc, c_loc) ? "equal!" : "unequal!");

	exit(EXIT_SUCCESS);
}
