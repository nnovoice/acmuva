/* UVa 11044 - Searching for Nessy */
#include <iostream>

using namespace std;

int main()
{
    int nCases = 0;
    int n = 0;
    int m = 0;
    int nRequiredToCover = 0;
    int mRequiredToCover = 0;
    int totalSonarsRequired = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> n >> m;
        if ((n % 3) == 0) {
            nRequiredToCover = n;
        }
        else {
            nRequiredToCover = n - 2;
            if ((nRequiredToCover % 3) != 0)
                nRequiredToCover = n - 1;
        }

        if ((m % 3) == 0) {
            mRequiredToCover = m;
        }
        else {
            mRequiredToCover = m - 2;
            if ((mRequiredToCover % 3) != 0)
                mRequiredToCover = m - 1;
        }

        //totalSonarsRequired = (nRequiredToCover / 3) + (mRequiredToCover / 3); // BUG here :-(
        totalSonarsRequired = (nRequiredToCover * mRequiredToCover) / 9;
        cout << totalSonarsRequired << endl;
    }
    return 0;
}
