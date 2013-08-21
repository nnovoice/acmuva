#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

const int MAXCHARS = 100;

int main()
{
    int nCases = 0;
    char input[MAXCHARS] = {' '};
    int len = 0;

    cin >> nCases;

    for (int i = 0; i < nCases; ++i) {
        cin >> input;
        len = strlen(input);

        sort (input, input + len);

        do{
            cout << input << endl;
        }
        while(std::next_permutation(input, input + len));

        cout << endl;
    }

    return 0;
}
