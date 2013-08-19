#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

const int MAXCHARS = 1025;

int main()
{
    int nCases = 0;
    char input[MAXCHARS] = {' '};
    int len = 0;
    char caps = 'A';
    char small = 'a';
    vector<char> letterOrderVec;
    map<char, int> letterIDMap;
    vector<int> inputLetterIDs;

    for (int i = 0; i < 26; ++i) {
        letterOrderVec.push_back(caps + i);
        letterOrderVec.push_back(small + i);
    }

    for (unsigned int i = 0; i < letterOrderVec.size(); ++i) {
        //cout << letterOrderVec[i];
        letterIDMap[letterOrderVec[i]] = i;
    }

    cin >> nCases;

    for (int i = 0; i < nCases; ++i) {
        cin >> input;
        len = strlen(input);

        inputLetterIDs = vector<int>();
        for (int j = 0; j < len; ++j) {
            inputLetterIDs.push_back(letterIDMap[input[j]]);
        }

        sort (inputLetterIDs.begin(), inputLetterIDs.end());

        for (int k = 0; k < len; ++k) {
            input[k] = letterOrderVec[inputLetterIDs[k]];
        }

        // LEARNING: if we do next_permutation on the input, the order is according to
        // the ASCII order and not like how the problem wants. So, doing next_perm on the
        // IDs gets us doing :-)
//        do{
//            cout << input << endl;
//        }
//        while(std::next_permutation(input, input + len));
        do {
            for (int k = 0; k < len; ++k) {
                input[k] = letterOrderVec[inputLetterIDs[k]];
            }
            cout << input << endl;
        }
        while (next_permutation(inputLetterIDs.begin(), inputLetterIDs.end()));
    }

    return 0;
}
