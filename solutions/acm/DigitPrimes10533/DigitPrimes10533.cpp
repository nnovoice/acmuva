#include <iostream>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

const int NUMMAX  = 1000000;
bool isComposite[NUMMAX + 1];
int primeIndexStore[NUMMAX + 1];
map<int, int> digitSumMap;

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
    int digitSum = 0;

    //memset(isComposite, 0, sizeof(bool) * (NUMMAX));
    //memset(primeIndexStore, 0, sizeof(int) * (NUMMAX));

    isComposite[0] = true;
    isComposite[1] = true;
    int primeIndex = -1;
    for (int m = 2; m <= upperBoundSquareRoot; m++) {
        if (!isComposite[m]) {
            digitSum = digitSumMap[m];
            if (digitSum == 0) {
                digitSum = GetDigitsSum(m);
                digitSumMap[m] = digitSum;
            }
            primeIndexStore[m] = ++primeIndex;
            for (int k = m * m; k <= NUMMAX; k += m)
                isComposite[k] = true;
        }
    }

    for (int m = upperBoundSquareRoot; m <= NUMMAX; m++)
    {
        if (!isComposite[m]) {
            primeIndexStore[m] = ++primeIndex;
            digitSum = digitSumMap[m];
            if (digitSum == 0) {
                digitSum = GetDigitsSum(m);
                digitSumMap[m] = digitSum;
            }
        }
    }
}

int main()
{
    int nCases = 0;
    int rangeStart = 0;
    int rangeEnd = 0;
    int temp = 0;
    map<int, int> digitPrimesMap;

    int nDigitPrimes = 0;
    int digitSum = 0;

    genPrimes();

    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf("%d %d", &rangeStart, &rangeEnd);
        //printf("Debug: %d %d\n", rangeStart, rangeEnd);
        if (rangeStart > rangeEnd) {
            temp = rangeStart;
            rangeStart = rangeEnd;
            rangeEnd = temp;
        }

        nDigitPrimes = 0;
        for (int j = rangeStart; j <= rangeEnd; ++j) {
            //printf("Debug: j= %d\n", j);
            digitSum = digitSumMap[j];

            if (isComposite[j] == false && isComposite[digitSum] == false) {
                ++nDigitPrimes;
                //printf("Debug: num = %d nDigitPrimes= %d\n", j, nDigitPrimes);
            }
        }
        printf("%d\n", nDigitPrimes);
    }

    return 0;
}
