#include <stdio.h>

int main()
{
    int nCases = 0;
    int amplitude = 0;
    int frequency = 0;

    scanf("%d", &nCases);

    for (int idx = 0; idx < nCases; ++idx) {
        if (idx > 0) printf("\n\n");

        scanf("%d", &amplitude);
        scanf("%d", &frequency);

        for (int i = 0; i < frequency; ++i) {
            if (i > 0) printf("\n\n");

            for(int j = 1; j <= amplitude; ++j) {
                for (int k = 1; k <= j; ++k)
                    printf("%d", j);
                printf("\n");
            }
            for(int j = (amplitude - 1); j >= 0; --j) {
                for (int k = 1; k <= j; ++k)
                    printf("%d", j);
                if (j > 1) printf("\n");
            }
        }
    }

    return 0;
}
