#include <iostream>
#include <map>
#include <cmath>
using namespace std;

//const unsigned int MAXNUM = 2147483648; // 2^31
const int NUMPOSSIBLEPRIMEDIVISORS  = 46340; // close to sqrt of MAXNUM
bool isComposite[NUMPOSSIBLEPRIMEDIVISORS + 1];
int primes[NUMPOSSIBLEPRIMEDIVISORS + 1];
int numPrimes;
int divisorsOfA[NUMPOSSIBLEPRIMEDIVISORS + 1];
int divisorsOfB[NUMPOSSIBLEPRIMEDIVISORS + 1];

void genPrimes()
{
    int upperBoundSquareRoot = NUMPOSSIBLEPRIMEDIVISORS;

    isComposite[0] = true;
    isComposite[1] = true;
    int primeIndex = -1;
    for (int m = 2; m <= upperBoundSquareRoot; ++m) {
        if (!isComposite[m]) {
            primes[++primeIndex] = m;
            ////cout << "Debug: "  << primes[primeIndex - 1] << endl;
            for (int k = m * m; k <= NUMPOSSIBLEPRIMEDIVISORS; k += m)
                isComposite[k] = true;
        }
    }

    numPrimes = primeIndex + 1;
    ////cout << "Debug: "  << "done with primes." << endl;
}

map<int, int> GetDivisors(int a)
{
    map<int, int> divisors;
    divisors[1] = 1; // 1 is always a divisor
    int divisorMultiple = 0;
    int squareRootA = (int)sqrt((double)a);
    //cout << "Debug: " << "sqrt of " << a << " = " << squareRootA << endl;
    for (int i = 0; ((primes[i] <= squareRootA) && (i < numPrimes)); ++i) {
        ////cout << "Debug: " << "primes[" << i << "]= " << primes[i] << endl;
        ////cout << "Debug: " << a << "% " << primes[i] << " = " << (a % primes[i]) << endl;
        if ((a % primes[i]) == 0) {
            if (divisors[primes[i]] == 0)
                divisors[primes[i]] = 1;

            divisorMultiple = primes[i];
            for (int j = 2; divisorMultiple <= a; ++j) {
                divisorMultiple = primes[i] * j;
                if ((a % divisorMultiple) == 0) {
                    if (divisors[divisorMultiple] == 0) {
                        divisors[divisorMultiple] = 1;
                    }
                }
            }
        }
    }
    return divisors;
}

int gcd (int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int gcdOfNums = 0;
    int aMultiple = 0;
    int bMultiple = 0;

    map<int, int> divisorsOfA = GetDivisors(a);
    //cout << "Debug: " << "got divisors of " << a << endl;
    map<int, int> divisorsOfB = GetDivisors(b);
    //cout << "Debug: " << "got divisors of " << b << endl;

    map<int, int>::iterator iterA = divisorsOfA.begin();
    map<int, int>::iterator iterAEnd = divisorsOfA.end();
    map<int, int>::iterator iterB = divisorsOfB.begin();
    map<int, int>::iterator iterBEnd = divisorsOfB.end();

    for (; iterA != iterAEnd && iterB != iterBEnd; ++iterA, ++iterB) {
        aMultiple = (*iterA).second;
        bMultiple = (*iterB).second;
        if (divisorsOfB[aMultiple] != 0 && gcdOfNums < aMultiple)
            gcdOfNums = aMultiple;
        if (divisorsOfA[bMultiple] != 0 && gcdOfNums < bMultiple)
            gcdOfNums = bMultiple;
    }

    return gcdOfNums;
}

int main()
{
    int a = 0;
    int b = 0;
    int gcdOfNums = 0;
    long long int lcmOfNums = 0;
    int nCases = 0;

    genPrimes();

    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> a >> b;
        gcdOfNums = gcd (a, b);
        if (gcdOfNums == 0) {
            cout << 0 << " " << 0;
        }
        else {
            if (gcdOfNums == 1) {
                if (a == 1 || b == 1) {
                    cout << gcdOfNums << " ";
                    lcmOfNums = (a * b)/gcdOfNums;
                    cout << lcmOfNums;
                }
                else {
                    cout << -1;
                }
            }
            else {
                cout << gcdOfNums << " ";
                lcmOfNums = ((long long)a * (long long)b)/(long long)gcdOfNums;
                cout << lcmOfNums;
            }
        }

        cout << endl;
        /////cout << "Debug: " << "GCD= " << gcdOfNums << endl;
    }

    return 0;
}
