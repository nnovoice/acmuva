#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXLINELENGTH = 1025;

int main()
{
    int nLeftMaleConnectors = 0;
    int nLeftFemaleConnectors = 0;
    int nRightMaleConnectors = 0;
    int nRightFemaleConnectors = 0;
    char connectors[MAXLINELENGTH] = {'\0'};
    int nCases = 0;
    int j = 0;

    cin >> nCases;
    cin.getline(connectors, MAXLINELENGTH);
    for (int i = 0; i < nCases; ++i) {
        nLeftMaleConnectors = 0;
        nLeftFemaleConnectors = 0;
        nRightMaleConnectors = 0;
        nRightFemaleConnectors = 0;
        cin.getline(connectors, MAXLINELENGTH);
        //scanf("%[^\n]", connectors);
        //cout << "Debug: " << connectors << endl;
        //printf("Debug: %s\n", connectors);
        j = 0;
        while (connectors[j] != '\0') {
            if (connectors[j] == ' ') {
                ++j;
                continue;
            }
            switch (connectors[j]) {
            case 'M':
                nLeftMaleConnectors += 1;
                break;
            case 'F':
                nLeftFemaleConnectors += 1;
                break;
            default:
                break;
            }

            switch (connectors[j + 1]) {
            case 'M':
                nRightMaleConnectors += 1;
                break;
            case 'F':
                nRightFemaleConnectors += 1;
                break;
            default:
                break;
            }

            j += 2;
        }

        //printf("Debug: LeftM=%d, RightF=%d, LeftF=%d, RightM=%d\n", \
        //       nLeftMaleConnectors, nRightFemaleConnectors, nLeftFemaleConnectors, nRightMaleConnectors);

        //cin.getline(connectors, MAXLINELENGTH);
        //scanf("%[^\n]", connectors);
        //cout << "Debug: again" << connectors << endl;
        //printf("Debug: %s\n", connectors);
        if ((nLeftMaleConnectors == nRightFemaleConnectors) &&
            (nRightMaleConnectors == nLeftFemaleConnectors))
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}
