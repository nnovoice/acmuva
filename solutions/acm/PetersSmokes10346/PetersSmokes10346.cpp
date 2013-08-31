#include <iostream>
//#include <climits>
using namespace std;

int main()
{
    unsigned long long int n = 0;
    unsigned long long int k = 0;
    unsigned long long int numCigarettes = 0;
    unsigned long long int numNewCigarettes = 0;
    unsigned long long int numButts = 0;

    while (cin >> n >> k) {
        numCigarettes = n;
        numButts = numCigarettes;

        while (1) {
            numNewCigarettes = (numButts / k);
            numCigarettes += numNewCigarettes;
            numButts = numNewCigarettes + (numButts % k);
            if (numNewCigarettes == 0 && numButts < k)
                break;
        }

        cout << numCigarettes << endl;
    }
    //cout << "INT_MAX= " << INT_MAX << endl;
    //cout << "UINT_MAX= " << UINT_MAX << endl;
    return 0;
}
