#include <stdio.h>
#include <algorithm>
const int MAXNUMBERS = 12;
int main()
{
    int numbers[MAXNUMBERS] = {0};
    int nElementsInSet = 0;
    int nCases = 0;
    while (scanf("%d", &nElementsInSet) != EOF) {
        if (nElementsInSet == 0) break;

        ++nCases;
        if (nCases > 1) printf("%s", "\n");

        for (int i = 0; i < nElementsInSet; ++i) {
            scanf("%d", &numbers[i]);
        }

        std::sort(numbers, numbers + nElementsInSet);

        for (int i = 0; i < nElementsInSet; ++i){
            for (int j = i + 1; j < nElementsInSet; ++j) {
                for (int k = j + 1; k < nElementsInSet; ++k) {
                    for (int l = k + 1; l < nElementsInSet; ++l) {
                        for (int m = l + 1; m < nElementsInSet; ++m) {
                            for (int n = m + 1; n < nElementsInSet; ++n) {
                                printf("%d %d %d %d %d %d\n", numbers[i], numbers[j], numbers[k], numbers[l], numbers[m], numbers[n]);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
