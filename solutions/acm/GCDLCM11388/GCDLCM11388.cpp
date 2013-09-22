#include <iostream>

using namespace std;

unsigned int gcd (unsigned int a, unsigned int b)
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
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int gcdOfNums = 0;
    int nCases = 0;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> a >> b;
        gcdOfNums = gcd (a, b);
        if (gcdOfNums == 1) {
            if (a == 1 || b == 1) {
                cout << gcdOfNums << " ";
                cout << ((a > b) ? a : b);
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
                cout << ((a > b) ? a : b);
            }
        }
        cout << endl;
        ///cout << "Debug: " << "GCD= " << gcdOfNums << endl;
    }

    return 0;
}
