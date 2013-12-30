#include <iostream>
#include <string.h>
using namespace std;

const int MAXCHARS = 2001;
const int NUMLETTERS = 26;

int main()
{
    int nCases = 0;
    char sentence[MAXCHARS] = {'\0'};
    int letterCounts[NUMLETTERS] = {0};
    int index = 0;
    int maxFrequency = 0;
    char letter = ' ';
    cin >> nCases;
    cin.getline(sentence, MAXCHARS); // read off the '\n' after the nCases
    while (nCases--) {
        maxFrequency = 0;
        memset(letterCounts, 0, sizeof(int) * NUMLETTERS);
        cin.getline(sentence, MAXCHARS);
        //cout << "Debug: " << "sentence= " << sentence << endl;
        for (int i = 0; sentence[i] != '\0'; ++i) {
            index = -1;
            if (sentence[i] >= 'A' && sentence[i] <= 'Z') {
                sentence[i] = 'a' + (sentence[i] - 'A');
                index = sentence[i] - 'a';
            }
            else if (sentence[i] >= 'a' && sentence[i] <= 'z') {
                index = sentence[i] - 'a';
            }

            if (index != -1) {
                letterCounts[index] += 1;
                if (letterCounts[index] > maxFrequency) {
                    maxFrequency = letterCounts[index];
                }
            }
        }

//        cout << "Debug: " << "MAX Letter count= " << maxFrequency << endl;
//        cout << "Debug: " << "Letter counts= " << endl;
//        for (int i = 0; i < NUMLETTERS; ++i) {
//            cout << letterCounts[i] << " ";
//        }
//        cout << endl;

        for (int i = 0; i < NUMLETTERS; ++i) {
            if (letterCounts[i] == maxFrequency) {
                letter = 'a' + i;
                cout << letter;
            }
        }
        cout << endl;
    }
    return 0;
}
