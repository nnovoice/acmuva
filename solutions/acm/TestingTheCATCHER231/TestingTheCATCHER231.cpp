#include <stdio.h>

const int MAXMISSILES = 100001;
int missiles[MAXMISSILES];
int longestNonDecreasingSeq[MAXMISSILES];

int GetMissilesIntercepted(int nMissiles)
{
    int nMaxMissilesIntercepted = 0;
    int curMissilesIntercepted = 0;
    for (int i = 0; i < nMissiles; ++i) {
        longestNonDecreasingSeq[i] = 1;
        for (int j = i - 1; j >= 0; --j) {
            if (missiles[i] <= missiles[j]) {
                curMissilesIntercepted = longestNonDecreasingSeq[j] + 1;
                if (longestNonDecreasingSeq[i] < curMissilesIntercepted) {
                    longestNonDecreasingSeq[i] = curMissilesIntercepted;
                    if (nMaxMissilesIntercepted < curMissilesIntercepted) {
                        nMaxMissilesIntercepted =  curMissilesIntercepted;
                    }
                }
                //break;
            }
        }
    }
    return nMaxMissilesIntercepted;
}

int main()
{
    int nMissilesIntercepted = 0;
    int missile = 0;
    int index = 0;
    int testCaseNum = 0;
    while (scanf("%d", &missile) != EOF) {
        if (missile == -1) {
            nMissilesIntercepted = GetMissilesIntercepted(index);

            if (testCaseNum > 0) printf("\n");

            printf("Test #%d:\n", ++testCaseNum);
            printf("  maximum possible interceptions: %d\n", nMissilesIntercepted);

            nMissilesIntercepted = 0;
            index = 0;

            scanf("%d", &missile);
            if (missile == -1) break;
            else {
                missiles[index++] = missile;
            }
        }
        else {
            missiles[index++] = missile;
        }
    }
    return 0;
}
