/* UVa 12004 - Bubble Sort */
#include <iostream>
using namespace std;

int main()
{
    unsigned int ncases = 0;
    unsigned long long int num = 0;
    unsigned long long int totalswaps = 0;

    cin >> ncases;

    for (unsigned int i = 0; i < ncases; ++i) {
        cin >> num;

        cout << "Case " << (i + 1) << ": ";

        totalswaps = (num * (num - 1)) / 2;
        if ((totalswaps % 2) == 0) {
            cout << (totalswaps / 2);
        }
        else {
            cout << totalswaps << "/" << 2;
        }
        cout << endl;
    }
    return 0;
}
