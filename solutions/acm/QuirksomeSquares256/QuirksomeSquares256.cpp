#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

const unsigned int MAXNUMBERS = 100000000;
const unsigned int MAXSQUARES = 19999;

unsigned int squares[MAXSQUARES];

void GetNumbers (unsigned int num, unsigned int& a, unsigned int& b, int digits)
{
    if (digits == 1) {
        a = num % 10;
        b = num / 10;
    }
    else if (digits == 2) {
        a = num % 100;
        b = num / 100;
    }
    else if (digits == 3) {
        a = num % 1000;
        b = num / 1000;
    }
    else if (digits == 4) {
        a = num % 10000;
        b = num / 10000;
    }
}

void CheckAndAddQuirk(unsigned int num, unsigned int& a, unsigned int& b, vector<int>& quirkVector)
{
    if (squares[a] > num)
        return;
    if (squares[b] > num)
        return;

    unsigned int quirkSum = squares[a + b];
    if (quirkSum == num) {
        quirkVector.push_back(num);
    }
}

int main()
{
    vector<int> quirkVectorArr[9];
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int i = 0;
    int nQuirkDigits = 0;

    for (i = 0; i < MAXSQUARES; ++i) {
        squares[i] = i * i;
    }

    for (i = 2; i <= 8; i += 2) {
        quirkVectorArr[i].push_back(0);
        quirkVectorArr[i].push_back(1);
    }

    for (i = 2; i < MAXNUMBERS; ++i) {
        if (i < 100) {
            GetNumbers(i, a, b, 1);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[2]);
        }
        else if (i < 10000) {
            GetNumbers(i, a, b, 2);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[4]);

            GetNumbers(i, a, b, 3);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[6]);
        }
        else if (i < 1000000) {
            GetNumbers(i, a, b, 3);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[6]);

            GetNumbers(i, a, b, 4);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[8]);
        }
        else {
            GetNumbers(i, a, b, 4);
            CheckAndAddQuirk(i, a, b, quirkVectorArr[8]);
        }
    }

    while (cin >> nQuirkDigits) {
        for (unsigned int j = 0; j < quirkVectorArr[nQuirkDigits].size(); ++j){
            cout << setw(nQuirkDigits) << setfill('0') << quirkVectorArr[nQuirkDigits][j] << endl;
        }
    }

    return 0;
}
