#include <stdio.h>
#include <stdlib.h>


int main()
{
    typedef enum {EMPTY, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING} Piece;
    typedef enum {BLACK, WHITE} Color;

    typedef struct {
        Piece piece;
        Color color;
    } Square;

    Square board[8][8] = {
        {
            {ROOK}, {KNIGHT}, {BISHOP}, {KING},
            {QUEEN}, {BISHOP}, {KNIGHT}, {ROOK}
        },
        {
            {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}, {PAWN}
        },
        [6] = {
            {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE},
            {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}, {PAWN, WHITE}
        },
        [7] = {
            {ROOK, WHITE}, {KNIGHT, WHITE}, {BISHOP, WHITE}, {KING, WHITE},
            {QUEEN, WHITE}, {BISHOP, WHITE}, {KNIGHT, WHITE}, {ROOK, WHITE}
        }
    };

    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++)
            printf("%d/%d ", board[i][j].piece, board[i][j].color);
        putchar('\n');
    }

    exit(EXIT_SUCCESS);
}
