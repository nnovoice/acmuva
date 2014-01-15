#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> jackCDsMap;
    int nCDsOfJack = 0, nCDsOfJill = 0;
    int nCDsOwnedByBoth = 0;
    int jackCDLabel = 0, jillCDLabel = 0;

    while (cin >> nCDsOfJack >> nCDsOfJill) {
        if (nCDsOfJack == 0 && nCDsOfJill == 0) break;

        jackCDsMap = map<int, int>();

        for (int i = 0; i < nCDsOfJack; ++i) {
            cin >> jackCDLabel;
            jackCDsMap[jackCDLabel] = 1;
        }

        nCDsOwnedByBoth = 0;

        for (int i = 0; i < nCDsOfJill; ++i) {
            cin >> jillCDLabel;
            if (jackCDsMap[jillCDLabel] != 0)
                ++nCDsOwnedByBoth;
        }
        cout << nCDsOwnedByBoth << endl;
    }
    return 0;
}
