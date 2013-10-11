#include <iostream>
#include <map>
#include <string>

using namespace std;
const int MAXSLOGANLENGTH = 101;
int main()
{
    char sloganFirstLine[MAXSLOGANLENGTH] = {'\0'};
    char sloganSecondLine[MAXSLOGANLENGTH] = {'\0'};
    map<string, string> slogans;
    int nSlogans = 0;
    int nFirstLineOfSlogans = 0;

    cin >> nSlogans;
    cin.getline(sloganFirstLine, MAXSLOGANLENGTH);
    for (int i = 0; i < nSlogans; ++i) {
        cin.getline(sloganFirstLine, MAXSLOGANLENGTH);
        cin.getline(sloganSecondLine, MAXSLOGANLENGTH);
        slogans[sloganFirstLine] = sloganSecondLine;
    }

    cin >> nFirstLineOfSlogans;
    cin.getline(sloganFirstLine, MAXSLOGANLENGTH);
    for (int i = 0; i < nSlogans; ++i) {
        cin.getline(sloganFirstLine, MAXSLOGANLENGTH);
        //cout << "Debug: " << sloganFirstLine << endl;
        cout << slogans[sloganFirstLine] << endl;
    }

    return 0;
}
