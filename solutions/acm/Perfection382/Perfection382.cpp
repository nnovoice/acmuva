#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
//#include <cstdio>
using namespace std;

const int NUMMAX  = 30000;
bool isComposite[NUMMAX + 1];
int primes[NUMMAX + 1];
int divisors[NUMMAX + 1];

int genPrimes()
{
    int upperBoundSquareRoot = (int)sqrt((double)NUMMAX);

    isComposite[0] = true;
    isComposite[1] = true;
    int primeIndex = -1;
    for (int m = 2; m <= upperBoundSquareRoot; ++m) {
        if (!isComposite[m]) {
            primes[++primeIndex] = m;
            for (int k = m * m; k <= NUMMAX; k += m)
                isComposite[k] = true;
        }
    }
    for (int m = upperBoundSquareRoot; m <= NUMMAX; m++)
    {
        if (!isComposite[m]) {
            primes[++primeIndex] = m;
        }
    }

    return (primeIndex + 1);
}

int main()
{
    //freopen("C:\\data\\personal\\programming\\acm\\input_files\\Perfection382\\input.txt", "r", stdin);
    int nPrimes = genPrimes();
    int nDivisors = 0;
    int product = 0;
    int divisorsSum = 0;
    map<int, int> divisorsMap;
    map<int, int>::iterator iterEnd;
    map<int, int>::iterator iter;

    int num = 0;

    cout << "PERFECTION OUTPUT" << endl;

    while (cin >> num) {
        if (num == 0) {
            cout << "END OF OUTPUT" << endl;
            break;
        }
        if (num == 1) {
            cout << std::right << std::setw(5) << num;
            cout << "  ";
            cout << "DEFICIENT" << endl;
            continue;
        }

        //cout << "Debug: " << "num= " << num <<endl;
        nDivisors = 0;
        for (int m = 0; ((m < nPrimes) && (primes[m] < num)); ++m) {
            if ((num % primes[m]) == 0) {
                divisors[nDivisors] = primes[m];
                //cout << "Debug: " << divisors[nDivisors] << " ";
                ++nDivisors;

                divisors[nDivisors] = num / primes[m];
                //cout << "Debug: " << divisors[nDivisors] << " ";

                ++nDivisors;
            }
        }
        //cout << "Debug: endl" << endl;

        divisorsMap = map<int, int>();

        for (int i = 0; i < nDivisors; ++i) {
            divisorsMap[divisors[i]] = 1;
            product = divisors[i];
            while (product < num) {
                product *= divisors[i];
                if ((product < num) && (num % product) == 0) {
                        divisorsMap[product] = 1;
                        divisorsMap[num / product] = 1;
                }
            }
            for (int j = 0; j < nDivisors; ++j) {
                product = divisors[i] * divisors[j];
                //cout << "Debug: " << "Product = " << product;
                if (product < num) {
                    if ((num % product) == 0) {
                        divisorsMap[product] = 1;
                        while (product < num) {
                            product *= product;
                            if ((product < num) && (num % product) == 0) {
                                    divisorsMap[product] = 1;
                                    divisorsMap[num / product] = 1;
                            }
                        }
                    }
                }
            }
        }

        divisorsSum = 1;
        //cout << "Debug: Divisors" << endl;
        iterEnd = divisorsMap.end();
        iter = divisorsMap.begin();
        for (; iter != iterEnd; ++iter) {
            divisorsSum += (*iter).first;
            //cout << "Debug: " << "Divisors Sum= " << divisorsSum << "Divisor= " << (*iter).first << endl;
        }
        //cout << "Debug: endl" << endl;

        cout << std::right << std::setw(5) << num;
        cout << "  ";

        if (divisorsSum == num) {
            cout << "PERFECT";
        }
        else if (divisorsSum < num) {
            cout << "DEFICIENT";
        }
        else {
            cout << "ABUNDANT";
        }
        cout << endl;
    }
    return 0;
}
