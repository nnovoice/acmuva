#include <iostream>
using namespace std;

int main0()
{
    // for a series of 1, 2, 3...8626...create the expected outputs
    int max = 8626 / 2;
    for (int i = 1; i <= max; ++i) {
        cout << i << endl << i << endl;
    }

    return 0;
}
