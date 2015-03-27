#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int eval_pos(const char board[8][8])
{
    int black_score = 0, white_score = 0;

    for(const char *p = *board; p < *(board + 8); p++) {
        if(isupper(*p))
            switch(*p) {
                case 'Q': white_score += 9; break;
                case 'R': white_score += 5; break;
                case 'B': white_score += 3; break;
                case 'N': white_score += 3; break;
                case 'P': white_score += 1; break;
            }
        else if(islower(*p))
            switch(*p) {
                case 'q': black_score += 9; break;
                case 'r': black_score += 5; break;
                case 'b': black_score += 3; break;
                case 'n': black_score += 3; break;
                case 'p': black_score += 1; break;
            }
    }

    return white_score - black_score;
}


int main()
{
    const char board[8][8] = {{'Q', 'B', 'P'}, {'q', 'r', 'p'}};

    printf("Chess score: %d\n", eval_pos(board));

    exit(EXIT_SUCCESS);
}
