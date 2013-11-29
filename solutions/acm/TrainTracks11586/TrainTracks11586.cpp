#include <stdio.h>

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

    scanf("%d\n", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf("%[^\n]", connectors);
        j = 0;
        while (connectors[j] != '\0') {
            switch (connectors[j]) {
            case 'M':
                    if ((j % 2) == 0)
                        nLeftMaleConnectors += 1;
                    else
                        nRightMaleConnectors += 1;
                break;
            case 'F':
                if ((j % 2) == 0)
                        nLeftFemaleConnectors += 1;
                    else
                        nRightFemaleConnectors += 1;
                break;
            default:
                break;
            }
            ++j;
        }
        scanf("%s", connectors); // read the '\n'
        if ((nLeftMaleConnectors == nRightFemaleConnectors) &&
            (nRightMaleConnectors == nLeftFemaleConnectors))
            printf("LOOP\n");
        else
            printf("NO LOOP\n");
    }

    return 0;
}
