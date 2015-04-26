#include <stdio.h>
#include <stdlib.h>

enum chess_pieces {KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

int main()
{
    const int piece_value[] = {
        [KING] = 200, [QUEEN] = 9, [ROOK] = 5,
        [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1
    };

    exit(EXIT_SUCCESS);
}
