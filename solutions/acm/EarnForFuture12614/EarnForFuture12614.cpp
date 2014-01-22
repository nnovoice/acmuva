#include <stdio.h>

int main()
{
    int ncases = 0;
    scanf("%d", &ncases);

    int nNums = 0;
    int num = 0;
    int maxNum = 0;

    for (int caseNum = 1; caseNum <= ncases; ++caseNum) {
        maxNum = 0;
        scanf("%d", &nNums);
        for (int i = 0; i < nNums; ++i) {
            scanf("%d", &num);
            if (maxNum < num)
                maxNum = num;
        }
        printf("case %d: %d\n", caseNum, maxNum);
    }

    return 0;
}
