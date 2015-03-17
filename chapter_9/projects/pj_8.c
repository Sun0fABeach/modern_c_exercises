#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

int roll_dice()
{
    return (rand() % 6) + (rand() % 6) + 2;
}

bool play_game()
{
    int points = roll_dice(), new_points;

    printf("You rolled: %d\n", points);
    switch(points) {
        case 7: case 11:
            return true;
        case 2: case 3: case 12:
            return false;
    }

    printf("Your point is: %d\n", points);
    while(true) {
        new_points = roll_dice();
        printf("You rolled: %d\n", new_points);
        if(new_points == 7)
            return false;
        if(new_points == points)
            return true;
    }
}

int main()
{
    char c;
    unsigned short wins = 0, losses = 0;

    srand(time(NULL));

    while(true) {
        if(play_game()) {
            puts("You win!\n");
            wins++;
        } else {
            puts("You lose!\n");
            losses++;
        }
        while(true) {
            printf("Play again? (y/n): ");
            scanf(" %c", &c);
            c = toupper(c);
            if(c == 'Y') break;
            if(c == 'N') goto display_score;
        }
    }

    display_score:
    printf("Wins: %hu   Losses: %hu\n", wins, losses);

    exit(EXIT_SUCCESS);
}
