/* UVa 12289 - one two three */
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char word[6] = { ' ' };
    int length = 0;
    int nCases = 0;
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> word;
        length = strlen(word);
        if (length == 5) {
            cout << "3";
        }
        else {
             // one oxe xne onx
             if ((word[0] == 'o' && word[2] == 'e') ||
                 (word[1] == 'n' && word[2] == 'e') ||
                 (word[0] == 'o' && word[1] == 'n'))
                    cout << "1";
             else
                cout << "2";
             // two txo xwo twx
        }
        cout << endl;
    }
    return 0;
}
