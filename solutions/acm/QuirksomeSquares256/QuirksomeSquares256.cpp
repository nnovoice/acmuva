#include <iostream>
#include <iomanip>

using namespace std;

const unsigned int MAXNUMBERS = 100000000;
const unsigned int MAXSQUARES = 19999;

unsigned int squares[MAXSQUARES];
unsigned int quirkNums[MAXSQUARES];

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int i = 0;
    unsigned int nDigits = 0;
    unsigned int quirkSum = 0;
    int index = 0;
    int nQuirkDigits = 0;
    unsigned int maxQuirkNum = 0;

    for (i = 0; i < MAXSQUARES; ++i) {
        squares[i] = i * i;
    }

    for (i = 1; i < MAXNUMBERS; ++i) {
        if (i < 100) {
            nDigits = 1;
            a = i % 10;
            b = i / 10;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;

            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[2] += 1;
                quirkNums[++index] = i;
            }
        }
        else if (i < 10000) {
            nDigits = 2;
            a = i % 100;
            b = i / 100;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;
            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[2] += 1;
                quirkNums[++index] = i;
            }

            a = i % 1000;
            b = i / 1000;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;
            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[4] += 1;
                quirkNums[++index] = i;
            }
        }
        else if (i < 1000000) {
            nDigits = 3;
            a = i % 1000;
            b = i / 1000;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;
            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[6] += 1;
                quirkNums[++index] = i;
            }

            nDigits = 4;
            a = i % 10000;
            b = i / 10000;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;
            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[8] += 1;
                quirkNums[++index] = i;
            }
        }
        else {
            nDigits = 4;
            a = i % 10000;
            b = i / 10000;
            if (squares[a] > i)
                continue;
            if (squares[b] > i)
                continue;
            quirkSum = squares[a + b];
            if (quirkSum == i) {
                //quirks[8] += 1;
                quirkNums[++index] = i;
            }
        }
        //cout << "Debug: " << "Num= " << i << " a = " << a << " b= " << b << endl;
    }

//    quirks[4] += quirks[2];
//    quirks[6] += quirks[4];
//    quirks[8] += quirks[6];
//    cout << "Debug: " << "quirks[2] = " << quirks[2] << endl;
//    cout << "Debug: " << "quirks[4] = " << quirks[4] << endl;
//    cout << "Debug: " << "quirks[6] = " << quirks[6] << endl;
//    cout << "Debug: " << "quirks[8] = " << quirks[8] << endl;

//    for (int j = 0; j <= index; ++j)
//        cout << "Debug: " << "quirkNums[" << j << "]= " << quirkNums[j] << endl;

    while (cin >> nQuirkDigits) {
        switch (nQuirkDigits){
        case 2:
            maxQuirkNum = 100;
            break;
        case 4:
            maxQuirkNum = 10000;
            break;
        case 6:
            maxQuirkNum = 1000000;
            break;
        case 8:
            maxQuirkNum = MAXNUMBERS;
            break;
        default:
            break;
        }

        for (int j = 0; j <= index; ++j){
            if (quirkNums[j] < maxQuirkNum)
                cout << setw(nQuirkDigits) << setfill('0') << quirkNums[j] << endl;
        }
    }

    return 0;
}
