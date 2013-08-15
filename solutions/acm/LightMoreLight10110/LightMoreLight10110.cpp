/* UVa 10110 - Light More Light */
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    vector<unsigned long long int> squares;
    unsigned long long int uIntMaxValue = (unsigned long long int) UINT_MAX;
    for (unsigned long long int i = 1; (i * i) <= uIntMaxValue; ++i) {
        squares.push_back(i * i);
    }

//    for (unsigned int i = 0; i < squares.size(); ++i)
//        cout << i << " " << squares[i] << endl;

    unsigned long int num = 0;
    bool switchState = false;
    while (cin >> num) {
        if (num == 0)
            break;

        switchState = binary_search(squares.begin(), squares.end(), num);

        if (switchState == true)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

//    cout << "uint_max= " << UINT_MAX << endl;
//    cout << "long_max= " << LONG_MAX << endl;
//    cout << "long long max= " << LONG_LONG_MAX << endl;
//    cout << "unsigned long long max= " << ULONG_LONG_MAX << endl;

    return 0;
}
