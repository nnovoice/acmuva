#include <iostream>
//#include <climits>
using namespace std;

int main()
{
    unsigned long long int n = 0;
    unsigned long long int k = 0;
    unsigned long long int numCigarettes = 0;
    unsigned long long int remainder = 0;

    while (cin >> n >> k) {
        numCigarettes = 0;
        remainder = 0;

        while (n > 0) {
            numCigarettes += n;
            remainder += (n % k);
            n /= k;
        }

        numCigarettes += (remainder / k);

        cout << numCigarettes << endl;
    }
    //cout << "INT_MAX= " << INT_MAX << endl;
    //cout << "UINT_MAX= " << UINT_MAX << endl;
    return 0;
}
