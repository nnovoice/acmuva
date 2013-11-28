#include <iostream>
#include <string.h>

using namespace std;

const int MAXDEVICES = 21; // 1 more than the actual because we will use index from 1

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

    while (cin >> nDevices >> mOperations >> maxCapacity) {
        if ((nDevices == 0) && (mOperations == 0) && (maxCapacity == 0)) break;

        if (sequenceNum > 0) cout << endl;

        memset(deviceStates, false, sizeof(bool) * MAXDEVICES);
        memset(capacities, 0, sizeof(int) * MAXDEVICES);
        consumedCapacity = 0;
        maxConsumedCapacity = 0;
        fuseBlown = false;

        // start index at 1
        for (int i = 1; i <= nDevices; ++i) cin >> capacities[i];

        for (int i = 0; i < mOperations; ++i) {
            cin >> deviceNum;
            if (fuseBlown == false) {
                deviceStates[deviceNum] = (deviceStates[deviceNum] == true) ? false : true;
                if (deviceStates[deviceNum] == true) {
                    consumedCapacity += capacities[deviceNum];
                }
                else {
                    consumedCapacity -= capacities[deviceNum];
                }

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

        cout << "Sequence " << ++sequenceNum << endl;
        if (fuseBlown == true) {
            cout << "Fuse was blown." << endl;
        }
        else {
            cout << "Fuse was not blown." << endl;
            cout << "Maximal power consumption was " << maxConsumedCapacity << " amperes." << endl;
        }
    }
    return 0;
}
