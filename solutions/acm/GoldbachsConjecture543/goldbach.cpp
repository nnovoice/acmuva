/* UVa 543 - Goldbach's Conjecture */
#define NUMMAX 1000001
#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;

bool isComposite[NUMMAX + 1];
int primeIndexStore[NUMMAX + 1];

void genPrimes()
{
    int upperBoundSquareRoot = (int)sqrt((double)NUMMAX);

    memset(isComposite, 0, sizeof(bool) * (NUMMAX));
    memset(primeIndexStore, 0, sizeof(int) * (NUMMAX));

    isComposite[0] = true;
    isComposite[1] = true;
    int primeIndex = -1;
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
        if (!isComposite[m]) {
            primeIndexStore[m] = ++primeIndex;
            //cout << m << "," << primeIndex << endl;
            for (int k = m * m; k <= NUMMAX; k += m)
                isComposite[k] = true;
        }
    }

    for (int m = upperBoundSquareRoot; m <= NUMMAX; m++)
    {
        if (!isComposite[m]) {
            primeIndexStore[m] = ++primeIndex;
            //cout << m << "," << primeIndex << endl;
        }
    }
}

int main()
{
    int num = 0;
    int diff = 0;
    int nearestPrime = 0;

    genPrimes();

    while (cin >> num) {
        if (num == 0) break;

        // find the nearest prime
        for (nearestPrime = num - 1; nearestPrime > 1; nearestPrime -= 2) {
            if (isComposite[nearestPrime] == false) {
                diff = num - nearestPrime;
                if (isComposite[diff] == false) {
                    cout << num << " = " << diff << " + " << nearestPrime << endl;
                    break;
                }
            }
        }
    }



}
