#include <iostream>

using namespace std;

unsigned long long gcd (unsigned long long a, unsigned long long b)
{
    if (a == 1)
        return 1;
    if (b == 1)
        return 1;
    if (a == 0 && b == 0)
        return 0;
    if (a == 0 && b != 0)
        return b;
    if (b == 0 && a != 0)
        return a;
    if (a > b) {
        return gcd (a - b, b);
    }
    else {
        return gcd (a, b - a);
    }
}

int main()
{
    unsigned long long a = 0;
    unsigned long long b = 0;
    unsigned long long gcdOfNums = 0;
    unsigned long long lcmOfNums = 0;
    int nCases = 0;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> a >> b;
        gcdOfNums = gcd (a, b);

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
            if (a == 0 || b == 0) {
                cout << 0;
            }
            else {
                lcmOfNums = (a * b)/gcdOfNums;
                cout << lcmOfNums;
            }
        }
        cout << endl;
        ///cout << "Debug: " << "GCD= " << gcdOfNums << endl;
    }

    return 0;
}
