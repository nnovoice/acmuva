#include <iostream>
using namespace std;

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int gcdOfNums = 0;
    unsigned int lcmOfNums = 0;
    int nCases = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> gcdOfNums >> lcmOfNums;
        a = gcdOfNums;
        b = lcmOfNums;
        if (gcdOfNums == 0 || lcmOfNums == 0) {
            cout << a << " " << b;
        }
        else if ((lcmOfNums % gcdOfNums) == 0)
        {
            cout << a << " " << b;
        }
        else {
            cout << -1;
        }
        cout << endl;
    }

    return 0;
}
