#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

int main()
{
    const int TOTALPRIMES = 25;
    int primes[TOTALPRIMES] = {2, 3, 5, 7, 11,
                               13, 17, 19, 23, 29,
                               31, 37, 41, 43, 47,
                               53, 59, 61, 67, 71,
                               73, 79, 83, 89, 97 };

    map<int, map<int, int> > factorialFactorsMap;
    map<int, int> factorsMap;
    map<int, int> factorsMapCopy;

    int tempNum = 0;
    int primeIndex = 0;
    for (int i = 2; i < 101; ++i) {
        tempNum = i;
        primeIndex = 0;
        while (tempNum != 1) {
            if ((tempNum % primes[primeIndex]) == 0) {
                factorsMap[primes[primeIndex]] += 1;
                //factorialFactorsMap[i][primes[primeIndex]] += 1;
                tempNum /= primes[primeIndex];
            }
            else {
                ++primeIndex;
            }
        }

        factorialFactorsMap[i] = factorsMap;
    }

    map<int, map<int, int> >::iterator endIter = factorialFactorsMap.end();
    map<int, map<int, int> >::iterator iter = factorialFactorsMap.begin();

    map<int, int>::iterator endFactorIter;
    map<int, int>::iterator factorIter;

    int numFactorsPrinted = 0;
    for (; iter != endIter; ++iter) {
        factorsMap = (*iter).second;
        cout << std::right << std::setw(3) << (*iter).first << "! =";
        endFactorIter = factorsMap.end();
        factorIter = factorsMap.begin();

        numFactorsPrinted = 1;
        for (; factorIter != endFactorIter; ++factorIter) {
            //cout << "(" << (*factorIter).first << "," << (*factorIter).second << ") ";
            if (numFactorsPrinted <= 15) {
                cout << std::right << std::setw(3) << (*factorIter).second;
                ++numFactorsPrinted;
            }
            else {
                cout << endl;
                cout << "      ";
                cout << std::right << std::setw(3) << (*factorIter).second;
                numFactorsPrinted = 1;
            }
        }
        cout << endl;
    }

//    int num = 0;
//    while (cin >> num) {
//        if (num == 0)
//            break;
//
//    }
    return 0;
}
