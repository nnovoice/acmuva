#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    int nCases = 0;
    char command[16] = {'\0'};
    int donation = 0;
    int totalDonation = 0;
    scanf("%d", &nCases);
    for (int i = 0; i < nCases; ++i) {
        scanf ("%s", command);
        //if (strcmp(command, "donate") == 0) {
        if (command[0] == 'd') {
            scanf("%d", &donation);
            totalDonation += donation;
        }
        else {
            printf("%d\n", totalDonation);
        }
    }
    return 0;
}
