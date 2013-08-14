#include <iostream>

using namespace std;

int main()
{
    int nCases = 0;
    int rangeA = 0;
    int rangeB = 0;
    int oddSum = 0;
    int temp = 0;

    cin >> nCases;


    for (int i = 0; i < nCases; ++i) {
        cin >> rangeA >> rangeB;
        if (rangeA > rangeB) {
            temp = rangeA;
            rangeA = rangeB;
            rangeB = temp;
        }
        oddSum = 0;
        for (int j = rangeA; j <= rangeB; ++j) {
            if ((j & 1)) oddSum += j;
        }
        cout << "Case " << (i + 1) << ": " << oddSum << endl;
    }
    return 0;
}
