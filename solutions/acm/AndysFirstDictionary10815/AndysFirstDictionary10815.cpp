#include <iostream>
#include <set>
#include <string.h>

const int MAXCHARS = 1025;

using namespace std;

int main()
{
    //int num = 0;  /// LEARNING: this was not required
    set<string> words;
    set<string>::iterator iter;
    set<string>::iterator iterEnd;

    set<string> newWords;
    set<string>::iterator newIter;
    set<string>::iterator newIterEnd;

    string input;
    char c = ' ';
    char charArr[MAXCHARS] = {' '};
    int charIndex = 0;
    while (cin >> input) {
        //cout << input << endl;
        words.insert(input);
    }

    iterEnd = words.end();
    for (iter = words.begin(); iter != iterEnd; ++iter) {
        //cout << (*iter) << endl;
        memset (charArr, '\0', sizeof(char) * MAXCHARS);
        int len = strlen((*iter).c_str());

        charIndex = -1;
        for (int i = 0; i < len; ++i) {
            c = (*iter)[i];
            if (c >= 'A' && c <= 'Z') {
                //cout << 'a' + (c - 'A');
                charArr[++charIndex] = 'a' + (c - 'A');
                //cout << "@" << charArr[charIndex] << "@";
            }
            else if (c >= 'a' && c <= 'z') {
                //cout << c;
                charArr[++charIndex] = c;
            }
            else { /// LEARNING: a word is a set of consecutive alphabets. If we get anything else, the word ends
                if (charIndex != -1)
                    newWords.insert(charArr);

                charIndex = -1;
                memset (charArr, '\0', sizeof(char) * MAXCHARS);
            }
            //cout << (*iter)[i];
        }

        if (charIndex != -1) /// LEARNING: if we get a set of chars which are non-alphabets, don't add without this check
            newWords.insert(charArr);
        //cout << endl;
    }

    newIterEnd = newWords.end();
    for (newIter = newWords.begin(); newIter != newIterEnd; ++newIter) {
//        if (num > 0) cout << endl; /// LEARNING: this was not required
//        else ++num;
        cout << (*newIter) << endl;
    }
    return 0;
}
