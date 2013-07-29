#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int getTimesToMoveFerry (queue<int>& bank, int nFerryLength)
{
    int nTimesToMove = 0;
    int nCarsLength = 0;
    bool movedOnce = false;

    while (bank.empty() == false) {
        if (movedOnce == false) {
            movedOnce = true;
            nTimesToMove += 1;
        }
        if ((nCarsLength + bank.front()) <= nFerryLength) {
            nCarsLength += bank.front();
            bank.pop();
        }
        else {
            nTimesToMove += 1;
            nCarsLength = 0;
        }
    }
    return nTimesToMove;
}

int main()
{
    queue<int> leftBankCars;
    queue<int> rightBankCars;
    int nFerryLength = 0;
    int nCases = 0;
    int nCars = 0;
    char side[6] = {' '};
    int nCarLength = 0;
    int nTimesLToR = 0;
    int nTimesRtoL = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++ i) {
        cin >> nFerryLength;
        nFerryLength *= 100;

        leftBankCars = queue<int>();
        rightBankCars = queue<int>();

        cin >> nCars;
        for (int j = 0; j < nCars; ++j) {
            cin >> nCarLength >> side;
            if (strcmp(side, "left") == 0) {
                leftBankCars.push (nCarLength);
            }
            else {
                rightBankCars.push (nCarLength);
            }
        }

        nTimesLToR = getTimesToMoveFerry (leftBankCars, nFerryLength);
        nTimesLToR = (nTimesLToR > 0) ? ((2 * nTimesLToR) - 1) : 0;

        nTimesRtoL = getTimesToMoveFerry (rightBankCars, nFerryLength);
        nTimesRtoL *= 2;

        (nTimesLToR > nTimesRtoL) ? (cout << nTimesLToR) : (cout << nTimesRtoL);
        cout << endl;
    }
    return 0;
}
