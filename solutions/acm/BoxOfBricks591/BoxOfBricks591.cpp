#include <iostream>

using namespace std;

int main()
{
    int stacks[50] = {0};
    int totalBricks = 0;
    int nStacks = 0;
    int commonWallHeight = 0;
    int bricksToMove = 0;
    int caseNum = 0;

    while (cin >> nStacks) {
        if (nStacks == 0) break;

        ++caseNum;

        totalBricks = 0;
        for (int i = 0; i < nStacks; ++i) {
            cin >> stacks[i];
            totalBricks += stacks[i];
        }

        commonWallHeight = totalBricks / nStacks;

        bricksToMove = 0;
        for (int i = 0; i < nStacks; ++i) {
            if (stacks[i] < commonWallHeight) {
                bricksToMove += (commonWallHeight - stacks[i]);
            }
        }
        cout << "Set #" << caseNum << endl;
        cout << "The minimum number of moves is " << bricksToMove << "." << endl << endl;
    }

    return 0;
}
