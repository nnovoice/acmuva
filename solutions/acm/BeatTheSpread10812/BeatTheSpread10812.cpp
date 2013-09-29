/* UVa 10812 - Beat The Spread*/
#include <stdio.h>

using namespace std;

typedef unsigned long int ULI;

int main()
{
    int nCases = 0;
    ULI scoreA = 0;
    ULI scoreB = 0;
    ULI scoresTotal = 0;
    ULI scoresDiff = 0;
    ULI totalOfTotalAndDiff = 0;
    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i)
    {
        scanf("%lu %lu", &scoresTotal, &scoresDiff);
        // x + y = scoresTotal
        // x - y = scoresDiff
        // 2x = scoresTotal + scoresDiff
        // x = (scoresTotal + scoresDiff) / 2
        // y = scoresTotal - x
        if (scoresTotal < scoresDiff) {
            printf("impossible\n");
        }
        else {
            totalOfTotalAndDiff = scoresTotal + scoresDiff;
            if ((totalOfTotalAndDiff % 2) != 0) {
                printf("impossible\n");
            }
            else {
                scoreA = totalOfTotalAndDiff / 2;
                scoreB = scoresTotal - scoreA;
                printf("%lu %lu\n", scoreA, scoreB);
            }
        }
    }
    return 0;
}
