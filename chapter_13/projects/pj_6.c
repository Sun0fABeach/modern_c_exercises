#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int main(int argc, char *argv[])
{
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter",
                       "Saturn", "Uranus", "Neptune", "Pluto"};
    int j;
    char *p, *q;

    for(int i = 1; i < argc; i++) {
        for(j = 0; j < NUM_PLANETS; j++) {
            p = argv[i], q = planets[j];
            while(toupper(*p) == toupper(*q)) {
                if(*p == '\0') {
                    printf("%s is planet %d\n", argv[i], j + 1);
                    goto planet_found;
                }
                p++, q++;
            }
        }
        if(j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
        planet_found: {}
    }

    exit(EXIT_SUCCESS);
}
