#include <iostream>

using namespace std;

const int MAXNUMBERS = 1001;

int main()
{
    int dailySalesNumbers[MAXNUMBERS] = {0};
    int nSalesNumbers = 0;
    int totalDaysOfBadSales = 0;
    int nCases = 0;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> nSalesNumbers;
        for (int j = 0; j < nSalesNumbers; ++j)
            cin >> dailySalesNumbers[j];

        totalDaysOfBadSales = 0;
        for (int k = 1; k < nSalesNumbers; ++k) {
            for (int l = k - 1; l >= 0; --l) {
                if (dailySalesNumbers[l] <= dailySalesNumbers[k])
                    ++totalDaysOfBadSales;
            }
        }
        cout << totalDaysOfBadSales << endl;

    }
    return 0;
}
