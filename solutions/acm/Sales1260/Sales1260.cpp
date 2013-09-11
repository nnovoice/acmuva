#include <stdio.h>

using namespace std;

const int MAXNUMBERS = 1001;

int main()
{
    int dailySalesNumbers[MAXNUMBERS] = {0};
    int nSalesNumbers = 0;
    int totalDaysOfBadSales = 0;
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf("%d", &nSalesNumbers);
        for (int j = 0; j < nSalesNumbers; ++j)
            scanf("%d", &dailySalesNumbers[j]);

        totalDaysOfBadSales = 0;
        for (int k = 1; k < nSalesNumbers; ++k) {
            for (int l = k - 1; l >= 0; --l) {
                if (dailySalesNumbers[l] <= dailySalesNumbers[k])
                    ++totalDaysOfBadSales;
            }
        }
        printf("%d\n", totalDaysOfBadSales);

    }
    return 0;
}
