#include <stdio.h>
#include <string.h>

const int BOARDSIZE = 8;
int board[BOARDSIZE][BOARDSIZE];
int nQueensPlaced = 0;

void PrintBoard(int board[BOARDSIZE][BOARDSIZE])
{
    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
            printf ("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool CanPlaceQueen(int board[BOARDSIZE][BOARDSIZE], int row, int col)
{
    if (board[row][col] == 1)
        return false;

    // check if a queen exists in the same row
    for (int j = 0; j < BOARDSIZE; ++j) {
        if (board[row][j] == 1)
            return false;
    }
    // check if a queen exists in the same col
    for (int i = 0; i < BOARDSIZE; ++i) {
        if (board[i][col] == 1)
            return false;
    }
    // check if a queen exists in the same diagnol - right diagnol exactly
    int x = row + 1;
    int y = col + 1;
    for (int i = 0; i < BOARDSIZE; ++i) {
        if (x < BOARDSIZE && y < BOARDSIZE) {
            if (board[x][y] == 1)
                return false;
            x += 1;
            y += 1;
        }
    }

    x = row - 1;
    y = col - 1;
    for (int i = 0; i < BOARDSIZE; ++i) {
        if (x < BOARDSIZE && y < BOARDSIZE) {
            if (board[x][y] == 1)
                return false;
            x -= 1;
            y -= 1;
        }
    }

    x = row + 1;
    y = col - 1;
    for (int i = 0; i < BOARDSIZE; ++i) {
        if (x < BOARDSIZE && y < BOARDSIZE) {
            if (board[x][y] == 1)
                return false;
            x += 1;
            y -= 1;
        }
    }

    x = row - 1;
    y = col + 1;
    for (int i = 0; i < BOARDSIZE; ++i) {
        if (x < BOARDSIZE && y < BOARDSIZE) {
            if (board[x][y] == 1)
                return false;
            x -= 1;
            y += 1;
        }
    }

    // check if a queen exists in the same diagnol - left diagnol now
    return true;
}

void PlaceQueens(int board[BOARDSIZE][BOARDSIZE], int x, int y)
{
    for (int i = 0; i < BOARDSIZE; ++i) {
        for (int j = 0; j < BOARDSIZE; ++j) {
            if (CanPlaceQueen(board, i, j) == true) {
                board[i][j] = 1;
                //PlaceQueens(board, i + 1, j + 1);
            }
        }
    }
}

int main()
{
    memset(board, 0, sizeof(board[0][0] * BOARDSIZE * BOARDSIZE));
    PlaceQueens(board, 0, 0);
    PrintBoard(board);
    return 0;
}
