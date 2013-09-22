#include <iostream>
#include <map>
#include <string.h>

using namespace std;
const int MAXINPUTLEN = 22;
int main()
{
    map<string, string> foreignWords;
    string englishWord;
    string foreignWord;
    char input[MAXINPUTLEN] = {'\0'};
    int inputLen = 0;
    string inputStr;
    int indexOfSpaceChar = 0;
    while (cin.getline(input, MAXINPUTLEN)) {
        inputLen = strlen(input);
        if (inputLen > 0) { // go only if we have good input
            inputStr = input;
            indexOfSpaceChar = inputStr.find(' ');
            if (indexOfSpaceChar > 0) { // are we reading the dictionary?
                englishWord = inputStr.substr(0, indexOfSpaceChar);
                foreignWord = inputStr.substr(indexOfSpaceChar + 1);
                //cout << "Debug: " << "english word= " << englishWord << " foreign word= " << foreignWord << endl;
                foreignWords[foreignWord] = englishWord;
            }
            else { // we are now reading foreign words and printing their english translation
                if (foreignWords.find(inputStr) != foreignWords.end()) {
                    cout << foreignWords[inputStr] << endl;
                }
                else {
                    cout << "eh" << endl;
                }
            }
        }
    }
    return 0;
}
