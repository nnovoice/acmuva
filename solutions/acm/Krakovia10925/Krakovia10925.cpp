#include <iostream>
#include <climits>

using namespace std;

typedef unsigned long long int ULLI;

int main()
{
    unsigned int nItems = 0;
    unsigned int nFriends = 0;
    unsigned int billNum = 0;
    ULLI totalValue = 0;
    ULLI itemValue = 0;
    ULLI eachFriendPays = 0;
    cout << "Debug: " << "max value of unsigned long long int= " << ULONG_LONG_MAX << endl;

    while (cin >> nItems >> nFriends) {
        if (nItems == 0 && nFriends == 0)
            break;

        totalValue = 0;
        for (unsigned int i = 0; i < nItems; ++i) {
            cin >> itemValue;
            totalValue += itemValue;
        }

        eachFriendPays = totalValue / nFriends;

        ///Bill #1 costs 16200000000: each friend should pay 5400000000
        cout << "Bill #" << ++billNum << " costs " << totalValue <<
                ": each friend should pay " << eachFriendPays << endl << endl;
    }

    return 0;
}
