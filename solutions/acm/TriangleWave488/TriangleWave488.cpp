#include <stdio.h>

int main()
{
    int nCases = 0;
    int amplitude = 0;
    int frequency = 0;

    scanf("%d", &nCases);

    for (int caseIndex = 0; caseIndex < nCases; ++caseIndex) {
        if (caseIndex > 0) printf("\n");

        scanf("%d", &amplitude);
        scanf("%d", &frequency);

        for (int i = 1; i <= frequency; ++i) {
            if (i > 1) printf("\n");

            for(int j = 1; j <= amplitude; ++j) {
                for (int k = 1; k <= j; ++k)
                    printf("%d", j);
                printf("\n");
            }
            for(int j = (amplitude - 1); j >= 1; --j) {
                for (int k = 1; k <= j; ++k)
                    printf("%d", j);
                //if (j != 1)
                printf("\n");
            }
        }
    }

    return 0;
}
