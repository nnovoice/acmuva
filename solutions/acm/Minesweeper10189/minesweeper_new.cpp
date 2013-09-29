#include <iostream>
using namespace std;

int minefield [102][102];
char mines [102][102];

void ProcessMine(int row, int col)
{
    int left	= col - 1;
    int top		= row - 1;
    int right	= col + 1;
    int bottom	= row + 1;

    minefield[top][left]	+= 1;

    minefield[top][col]		+= 1;

    minefield[top][right]	+= 1;

    minefield[row][right]	+= 1;

    minefield[bottom][right] += 1;

    minefield[bottom][col] += 1;

    minefield[bottom][left] += 1;

    minefield[row][left]	+= 1;
}

void PrintMineField(int nRows, int mCols)
{
    static int fieldNum = 0;
    fieldNum++;
    cout << "Field #" << fieldNum << ":" << endl;
    for (int row = 1; row <= nRows; row++)
    {
        for (int col = 1; col <= mCols; col++)
        {
                if (mines[row][col] == '*')
                        cout << '*';
                else
                        cout << minefield[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

void GetInputs(int n, int m)
{
    for (int row = 1; row <= n; row++)
    {
            for (int col = 1; col <= m; col++)
            {
                    cin >> mines[row][col];
            }
    }
}

void ResetMineField (int n, int m)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= m; col++)
        {
                minefield[row][col] = 0;
        }
    }
}

void ProcessMines (int n, int m)
{
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= m; col++)
        {
            if (mines[row][col] == '*')
                    ProcessMine(row, col);
        }
    }
}

bool IsValidInputSequence (int n, int m)
{
	bool valid = true;
	if (n == 0 && m == 0)
	{
			valid = false;
	}
	return valid;
}

int main()
{
    int n = 0, m = 0;
    while (cin >> n)
    {
        cin >> m;
        GetInputs(n, m);

		if (IsValidInputSequence (n, m)) {
		
			ResetMineField (n, m);

			ProcessMines (n, m);

			PrintMineField(n, m);
		}
		else {
			cout << endl;
			break;
		}
    }

    return 0;
}

