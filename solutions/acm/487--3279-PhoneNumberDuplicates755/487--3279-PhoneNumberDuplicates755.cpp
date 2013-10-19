#include <iostream>
#include <map>
#include <string.h>

using namespace std;

const int MAXCHARS = 1025;

int main()
{
    map<string, int> phoneNumberCountsMap;
    map<string, int>::iterator mapIter;
    map<string, int>::iterator mapIterEnd;
    char inputPhoneNumber[MAXCHARS] = {'\0'};
    char phoneNumber[MAXCHARS] = {'\0'};
    int digitsCount = 0;
    int digitIndex = 0;
    bool duplicatesFound = false;
    //            A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    int keys[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};
    // Q and Z have no mapping

    int nDataSets = 0;
    cin >> nDataSets;

    int nPhoneNumbers = 0;
    for (int i = 0; i < nDataSets; ++i) {
        if (i > 0) cout << endl; // blank line between datasets
        cin >> nPhoneNumbers;

        phoneNumberCountsMap = map<string, int>();
        duplicatesFound = false;

        for (int j = 0; j < nPhoneNumbers; ++j) {
            cin >> inputPhoneNumber;
            memset (phoneNumber, '\0', sizeof(char) * MAXCHARS);
            digitsCount = 0;
            digitIndex = 0;
            for (int k = 0; k < MAXCHARS && inputPhoneNumber[k] != '\0'; ++k) {
                if (inputPhoneNumber[k] == '-') continue;
                if (inputPhoneNumber[k] >= 'A' && inputPhoneNumber[k] <= 'Z') {
                    phoneNumber[digitIndex++] = '0' + keys[inputPhoneNumber[k] - 'A'];
                }
                else {
                    phoneNumber[digitIndex++] = inputPhoneNumber[k];
                }

                ++digitsCount;

                if (digitsCount == 3) {
                    phoneNumber[digitIndex++] = '-';
                }
            }

            phoneNumberCountsMap[phoneNumber] += 1;
            if (phoneNumberCountsMap[phoneNumber] > 1)
                duplicatesFound = true;
        }

        if (duplicatesFound) {
            mapIterEnd = phoneNumberCountsMap.end();
            for (mapIter = phoneNumberCountsMap.begin(); mapIter != mapIterEnd; ++mapIter) {
                if (mapIter->second > 1)
                    cout << mapIter->first << " " << mapIter->second << endl;
            }
        }
        else {
            cout << "No duplicates." << endl;
        }
    }

    return 0;
}
