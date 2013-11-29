#include <stdio.h>
#include <iostream>
using namespace std;

const int MAXLINELENGTH = 1025;

int main()
{
    int nFMConnectors = 0;
    int nFFConnectors = 0;
    int nMMConnectors = 0;
    int nTotalConnectors = 0;
    char connectors[MAXLINELENGTH] = {'\0'};
    int nCases = 0;
    int j = 0;

    cin >> nCases;
    cin.getline(connectors, MAXLINELENGTH);
    for (int i = 0; i < nCases; ++i) {
        nFMConnectors = 0;
        nFFConnectors = 0;
        nMMConnectors = 0;
        nTotalConnectors = 0;

        cin.getline(connectors, MAXLINELENGTH);

        j = 0;
        while (connectors[j] != '\0') {
            if (connectors[j] == ' ') {
                ++j;
                continue;
            }

            if (connectors[j] == 'M') {
                if (connectors[j + 1] == 'M') {
                    ++nMMConnectors;
                }
                else {
                    ++nFMConnectors;
                }
            }
            else {
                if (connectors[j + 1] == 'M') {
                    ++nFMConnectors;
                }
                else {
                    ++nFFConnectors;
                }
            }
            j += 2;
        }

        nTotalConnectors = nFMConnectors + nFFConnectors + nMMConnectors;
        if ((nTotalConnectors > 1) && (nFFConnectors == nMMConnectors))
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}
