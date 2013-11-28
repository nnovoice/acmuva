#include <stdio.h>
#include <string.h>

const int MAXDEVICES = 2001; // 1 more than the actual because we will use index from 1

int main()
{
    int sequenceNum = 0;
    bool deviceStates[MAXDEVICES] = {false};
    int capacities[MAXDEVICES] = {0};
    int nDevices = 0;
    int mOperations = 0;
    int deviceNum = 0;
    int maxCapacity = 0;
    int consumedCapacity = 0;
    int maxConsumedCapacity = 0;
    bool fuseBlown = false;

    while (scanf("%d%d%d", &nDevices, &mOperations, &maxCapacity) != EOF) {
        if ((nDevices == 0) && (mOperations == 0) && (maxCapacity == 0)) break;

        memset(deviceStates, false, sizeof(bool) * MAXDEVICES);
        memset(capacities, 0, sizeof(int) * MAXDEVICES);
        consumedCapacity = 0;
        maxConsumedCapacity = 0;
        fuseBlown = false;

        // start index at 1
        for (int i = 1; i <= nDevices; ++i) scanf("%d", &capacities[i]);

        for (int i = 0; i < mOperations; ++i) {
            scanf("%d", &deviceNum);
            if (fuseBlown == false) {
                deviceStates[deviceNum] = (deviceStates[deviceNum] == true) ? false : true;
                if (deviceStates[deviceNum] == true) {
                    consumedCapacity += capacities[deviceNum];
                }
                else {
                    consumedCapacity -= capacities[deviceNum];
                }
                //printf ("Debug: consumed=%d\n", consumedCapacity);

                if (consumedCapacity > maxCapacity) {
                    fuseBlown = true;
                }
                else {
                    if (consumedCapacity >= 0 && maxConsumedCapacity < consumedCapacity) {
                        maxConsumedCapacity = consumedCapacity;
                    }
                }
            }
        }

        ++sequenceNum;
        printf ("Sequence %d\n", sequenceNum);
        if (fuseBlown == true) {
            printf ("Fuse was blown.\n");
        }
        else {
            printf ("Fuse was not blown.\n");
            printf ("Maximal power consumption was %d amperes.\n", maxConsumedCapacity);
        }
        printf("\n"); // blank lin after each test case.
    }
    return 0;
}
