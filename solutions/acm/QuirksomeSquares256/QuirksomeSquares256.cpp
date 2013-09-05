#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const unsigned int MAXNUMBERS = 100000000;
const unsigned int MAXSQUARES = 19999;

unsigned int squares[MAXSQUARES];
unsigned int quirkNums[MAXSQUARES];

int main()
{
    vector<int> quirkVectorArr[9];
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int i = 0;
    unsigned int quirkSum = 0;
    int index = 0;
    int nQuirkDigits = 0;

    for (i = 0; i < MAXSQUARES; ++i) {
        squares[i] = i * i;
    }

    quirkVectorArr[2].push_back(0);
    quirkVectorArr[4].push_back(0);
    quirkVectorArr[6].push_back(0);
    quirkVectorArr[8].push_back(0);
    quirkVectorArr[2].push_back(1);
    quirkVectorArr[4].push_back(1);
    quirkVectorArr[6].push_back(1);
    quirkVectorArr[8].push_back(1);

    for (i = 2; i < MAXNUMBERS; ++i) {
        if (i < 100) {
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
                quirkVectorArr[2].push_back(i);
            }
        }
        else if (i < 10000) {
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
                quirkVectorArr[4].push_back(i);
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
                quirkVectorArr[6].push_back(i);
            }
        }
        else if (i < 1000000) {
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
                quirkVectorArr[6].push_back(i);
            }

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
                quirkVectorArr[8].push_back(i);
            }
        }
        else {
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
                quirkVectorArr[8].push_back(i);
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
        for (unsigned int j = 0; j < quirkVectorArr[nQuirkDigits].size(); ++j){
            cout << setw(nQuirkDigits) << setfill('0') << quirkVectorArr[nQuirkDigits][j] << endl;
        }
    }

    return 0;
}
