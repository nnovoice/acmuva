#include <iostream>
#include <set>
#include <string.h>

const int MAXCHARS = 1025;

using namespace std;

bool IsLetter(char c)
{
    if (c >= 'A' && c <= 'Z') {
        return true;
    }
    else if (c >= 'a' && c <= 'z') {
        return true;
    }
    return false;
}

int main()
{
    set<string> words;
    set<string>::iterator iter;
    set<string>::iterator iterEnd;

    char c = ' ';
    char prevChar = ' ';
    char input[MAXCHARS] = {' '};
    char charArr[MAXCHARS] = {' '};
    int charArrLen = 0;
    int charIndex = -1;
    bool continueWord = false;

    //while (cin.getline(input, MAXCHARS)) {
    while (cin >> input) {

        int len = strlen(input);
        //cout << "Debug: " << "input= " << input << " len= " << len << endl;

        if (len == 0) continue;

        if (continueWord == true) {
            continueWord = false;
        }
        else {
            charIndex = -1;
        }

        for (int i = 0; i < len; ++i) {
            c = input[i];
            if (c >= 'A' && c <= 'Z') {
                charArr[++charIndex] = 'a' + (c - 'A');
            }
            else if (c >= 'a' && c <= 'z') {
                charArr[++charIndex] = c;
            }
            else if (c == '-') {
                if (i != (len - 1)) {
                    prevChar = charArr[charIndex];
                    if (IsLetter(prevChar) == true) {
                        charArr[++charIndex] = c;
                    }
                    else {
                        continueWord = false;
                    }
                }
                else {
                    continueWord = true;
                }
            }
            else { // LEARNING: a word is a set of consecutive alphabets. If we get anything else, the word ends
                if (charIndex != -1) {
                    // If '-' occurs without a suffix (for instance hello-), remove all such '-' chars
                    while (charArr[charIndex] == '-') {
                        --charIndex;
                    }
                    charArr[charIndex + 1] = '\0';

                    charArrLen = strlen (charArr);
                    if (charArrLen > 0) {
                        //cout << "Debug: " << "char index= " << charIndex << " str= " << charArr << endl;
                        words.insert(charArr);
                    }
                }

                charIndex = -1;
                memset (charArr, '\0', sizeof(char) * MAXCHARS);
                continueWord = false;
            }
        }

        // LEARNING: if we get a set of chars which are non-alphabets, don't add without this check
        if (charIndex != -1 && continueWord == false) {
            words.insert(charArr);
        }

        if (continueWord == false) {

            charArrLen = strlen (charArr);
            if (charArrLen > 0) {
                //cout << "Debug: " << "char index= " << charIndex << " str= " << charArr << endl;
                words.insert(charArr);
            }
            charIndex = -1;
            memset (charArr, '\0', sizeof(char) * MAXCHARS);
        }
    }

    //string output;

    iterEnd = words.end();
    for (iter = words.begin(); iter != iterEnd; ++iter) {
        //output = (*iter);
        //cout << "Debug: " << " str= " << output << " len= " << strlen(output.c_str()) << endl;
        cout << (*iter) << endl;
    }
    return 0;
}
