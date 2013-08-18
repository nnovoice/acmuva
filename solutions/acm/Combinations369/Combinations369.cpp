#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    //unsigned long long int pascalTriangle[103][103] = {};
    long int pascalTriangle[103][103] = {};
    unsigned int N = 0;
    unsigned int K = 0;

    unsigned int i = 0;
    unsigned int j = 0;

    pascalTriangle[1][1] = 1;
    pascalTriangle[2][1] = 1; pascalTriangle[2][2] = 1;

    for (i = 3; i <= 102; ++i) {
        pascalTriangle[i][1] = 1; //cout << pascalTriangle[i][1] << ", ";
        for (j = 2; j < i; ++j) {
            pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
            //cout << pascalTriangle[i][j] << ", ";
        }
        pascalTriangle[i][j] = 1;
        //cout << pascalTriangle[i][j] << " " << endl;
    }

    while (cin >> N >> K) {
        if (N == 0 && K == 0)
            break;

        cout << N << " things taken " << K << " at a time is " << pascalTriangle[N + 1][K + 1] << " exactly." << endl;
    }
    //cout << "Debug: " << "Max value of long int= " << LONG_MAX << endl;

//    cout << "100 choose 6= " << pascalTriangle[101][7] << endl;
//    cout << "20 choose 5= " << pascalTriangle[21][6] << endl;
//    cout << "18 choose 6= " << pascalTriangle[19][7] << endl;
    return 0;
}
