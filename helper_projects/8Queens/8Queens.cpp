#include <stdio.h>
#include <string.h>

const int BOARDSIZE = 8;
int board[BOARDSIZE][BOARDSIZE];
int nQueensPlaced = 0;
int queensXStack[BOARDSIZE];
int queensYStack[BOARDSIZE];
int idx;

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
    idx = 0;
    bool queenPlaced = false;
    int i = 0;
    int j = 0;
    int lastI = 0;
    int lastJ = 0;
    for (i = 0; i < BOARDSIZE; ++i) {
        queenPlaced = false;
        for (j = 0; j < BOARDSIZE; ++j) {
            if (i == 0 && j == 0 && idx == 0) {
                if (CanPlaceQueen(board, i, j) == true) {
                    board[i][j] = 1;
                    queensXStack[idx] = i;
                    queensYStack[idx] = j;
                    ++idx;
                    queenPlaced = true;
                    //break; // move to the next row
                    //PlaceQueens(board, i + 1, j + 1);
                }
            }
            if (idx > 0 && queenPlaced == false) {
                //&& i == lastI && j != lastJ
                i = lastI;
                j = lastJ + 1;
                if (CanPlaceQueen(board, i, j) == true) {
                    board[i][j] = 1;
                    queensXStack[idx] = i;
                    queensYStack[idx] = j;
                    ++idx;
                    queenPlaced = true;
                    //break; // move to the next row
                    //PlaceQueens(board, i + 1, j + 1);
                }
            }
        }
        // were we able to place a queen? if not, backtrack
        if (queenPlaced == false) {
            --idx;
            board[queensXStack[idx]][queensYStack[idx]] = 0;
            lastI = queensXStack[idx];
            lastJ = queensYStack[idx];
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
