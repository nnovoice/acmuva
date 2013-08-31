#include <stdio.h>
//#include <iostream>
//#include <climits>
using namespace std;

int main()
{
    unsigned long int n = 0;
    unsigned long int k = 0;
    unsigned long int numCigarettes = 0;
    unsigned long int numNewCigarettes = 0;
    unsigned long int numButts = 0;

    while (scanf("%lu %lu", &n, &k) != EOF) {
        numCigarettes = n;
        numButts = numCigarettes;

        while (1) {
            numNewCigarettes = (numButts / k);
            numCigarettes += numNewCigarettes;
            numButts = numNewCigarettes + (numButts % k);
            if (numNewCigarettes == 0 && numButts < k)
                break;
        }

        printf("%lu\n", numCigarettes);
    }
    //cout << "INT_MAX= " << INT_MAX << endl;
    //cout << "UINT_MAX= " << UINT_MAX << endl;
    return 0;
}
