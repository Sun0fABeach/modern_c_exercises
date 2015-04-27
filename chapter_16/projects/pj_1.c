#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *country;
    int code;
} DialingCode;


int main()
{
    const DialingCode country_codes[] = {
        {"Argentina", 54}, {"Bangladesh", 880}, {"Brazil", 55}
    };
    int code;

    printf("Enter a dialing code: ");
    scanf("%d", &code);

    for(size_t i = 0; i < sizeof(country_codes)/sizeof(DialingCode); i++)
        if(country_codes[i].code == code) {
            printf(
                "Country with code %d: %s\n", code, country_codes[i].country
            );
            exit(EXIT_SUCCESS);
        }

    printf("No country with code %d found!\n", code);
    exit(EXIT_SUCCESS);
}

