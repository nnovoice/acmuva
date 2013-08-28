#include <stdio.h>

int main()
{
    int stacks[50] = {0};
    int totalBricks = 0;
    int nStacks = 0;
    int commonWallHeight = 0;
    int bricksToMove = 0;
    int caseNum = 0;

    while (scanf("%d", &nStacks) != EOF) {
        if (nStacks == 0) break;

        ++caseNum;

        totalBricks = 0;
        for (int i = 0; i < nStacks; ++i) {
            scanf("%d", &stacks[i]);
            totalBricks += stacks[i];
        }

        commonWallHeight = totalBricks / nStacks;

        bricksToMove = 0;
        for (int i = 0; i < nStacks; ++i) {
            if (stacks[i] < commonWallHeight) {
                bricksToMove += (commonWallHeight - stacks[i]);
            }
        }
        printf("Set #%d\n", caseNum);
        printf("The minimum number of moves is %d.\n\n", bricksToMove);
    }

    return 0;
}
