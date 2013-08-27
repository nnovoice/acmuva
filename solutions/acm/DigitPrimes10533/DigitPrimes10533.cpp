#include <iostream>
#include <stdio.h>
//#include <map>
//#include <algorithm>
#include <cmath>

using namespace std;

const int NUMMAX  = 1000000;
bool isComposite[NUMMAX + 1];
int nPrimeDigitsStore[NUMMAX + 1];

int GetDigitsSum (int num)
{
    int digitsSum = 0;
    int digit = 0;
    while (num != 0) {
        digit = num % 10;
        digitsSum += digit;
        num -= digit;
        num /= 10;
    }
    return digitsSum;
}

void genPrimes()
{
    int upperBoundSquareRoot = (int)sqrt((double)NUMMAX);
    int nDigitsPrime = 0;
    int digitSum = 0;

    //memset(isComposite, 0, sizeof(bool) * (NUMMAX));
    //memset(primeIndexStore, 0, sizeof(int) * (NUMMAX));

    isComposite[0] = true;
    isComposite[1] = true;
    //int primeIndex = -1;
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
        if (!isComposite[m]) {
            digitSum = GetDigitsSum(m);
            if (!isComposite[digitSum])
                nPrimeDigitsStore[m] = ++nDigitsPrime;
            else
                nPrimeDigitsStore[m] = nDigitsPrime;

            for (int k = m * m; k <= NUMMAX; k += m) {
                isComposite[k] = true;
                //nPrimeDigitsStore[m] = nDigitsPrime;
            }
        }
        else {
            nPrimeDigitsStore[m] = nDigitsPrime;
        }
    }

    for (int m = upperBoundSquareRoot; m <= NUMMAX; m++)
    {
        if (!isComposite[m]) {
            digitSum = GetDigitsSum(m);
            if (!isComposite[digitSum])
                nPrimeDigitsStore[m] = ++nDigitsPrime;
            else
                nPrimeDigitsStore[m] = nDigitsPrime;
        }
        else {
            nPrimeDigitsStore[m] = nDigitsPrime;
        }
    }
}

int main()
{
    int nCases = 0;
    int rangeStart = 0;
    int rangeEnd = 0;
    int temp = 0;
    int nDigitPrimes = 0;

    genPrimes();

//    for (int i = 1; i <= 999999; ++i) {
//        printf("%d %d\n", i, nPrimeDigitsStore[i]);
//    }

    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf("%d %d", &rangeStart, &rangeEnd);
        //printf("Debug: %d %d\n", rangeStart, rangeEnd);
        if (rangeStart > rangeEnd) {
            temp = rangeStart;
            rangeStart = rangeEnd;
            rangeEnd = temp;
        }

        nDigitPrimes = nPrimeDigitsStore[rangeEnd] - nPrimeDigitsStore[rangeStart];
        // if rangeStart is a digit prime, add 1
        if (!isComposite[rangeStart]) {
            if ((nPrimeDigitsStore[rangeStart] - nPrimeDigitsStore[rangeStart - 1]) == 1)
                ++nDigitPrimes;
        }

        printf("%d\n", nDigitPrimes);
    }

    return 0;
}
