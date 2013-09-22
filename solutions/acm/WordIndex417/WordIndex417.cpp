#include <iostream>
#include <map>

using namespace std;
const int MAXALPHABETS = 26;
const int MAXCHARSINWORD = 6;
int main()
{
    map<string, int> wordIndexMap;
    int wordIndex = 0;
    string str;
    char alphabets[MAXALPHABETS] = {' '};
    char word[MAXCHARSINWORD] = {' '};

    for (int i = 0; i < MAXALPHABETS; ++i) {
        alphabets[i] = 'a' + i;
    }
    for (int i = 0; i < MAXALPHABETS; ++i) {
        str = alphabets[i];
        wordIndexMap[str] = ++wordIndex;
        //cout << "Debug: " << "word= " << str << " index= " << wordIndexMap[str] << endl;
    }

    for (int i = 0; i < MAXALPHABETS; ++i) {
        word[0] = alphabets[i];
        for (int j = i + 1; j < MAXALPHABETS; ++j) {
            word[1] = alphabets[j];
            word[2] = '\0';
            str = word;
            wordIndexMap[str] = ++wordIndex;
            //cout << "Debug: " << "word= " << str << " index= " << wordIndexMap[str] << endl;
        }
    }

    for (int i = 0; i < MAXALPHABETS; ++i) {
        word[0] = alphabets[i];
        for (int j = i + 1; j < MAXALPHABETS; ++j) {
            word[1] = alphabets[j];
            for (int k = j + 1; k < MAXALPHABETS; ++k) {
                word[2] = alphabets[k];
                word[3] = '\0';
                str = word;
                wordIndexMap[str] = ++wordIndex;
                //cout << "Debug: " << "word= " << str << " index= " << wordIndexMap[str] << endl;
            }
        }
    }

    for (int i = 0; i < MAXALPHABETS; ++i) {
        word[0] = alphabets[i];
        for (int j = i + 1; j < MAXALPHABETS; ++j) {
            word[1] = alphabets[j];
            for (int k = j + 1; k < MAXALPHABETS; ++k) {
                word[2] = alphabets[k];
                for (int l = k + 1; l < MAXALPHABETS; ++l) {
                    word[3] = alphabets[l];
                    word[4] = '\0';
                    str = word;
                    wordIndexMap[str] = ++wordIndex;
                    //cout << "Debug: " << "word= " << str << " index= " << wordIndexMap[str] << endl;
                }
            }
        }
    }

    for (int i = 0; i < MAXALPHABETS; ++i) {
        word[0] = alphabets[i];
        for (int j = i + 1; j < MAXALPHABETS; ++j) {
            word[1] = alphabets[j];
            for (int k = j + 1; k < MAXALPHABETS; ++k) {
                word[2] = alphabets[k];
                for (int l = k + 1; l < MAXALPHABETS; ++l) {
                    word[3] = alphabets[l];
                    for (int m = l + 1; m < MAXALPHABETS; ++m) {
                        word[4] = alphabets[m];
                        word[5] = '\0';
                        str = word;
                        wordIndexMap[str] = ++wordIndex;
                        //cout << "Debug: " << "word= " << str << " index= " << wordIndexMap[str] << endl;
                    }
                }
            }
        }
    }

    while (cin >> str) {
        cout << wordIndexMap[str] << endl;
    }

    return 0;
}
