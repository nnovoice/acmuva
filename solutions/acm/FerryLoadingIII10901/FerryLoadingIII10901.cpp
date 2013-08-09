#include <iostream>
#include <queue>
#include <map>
#include <string.h>

using namespace std;

enum bank {leftbank, rightbank};

void StayOrMoveToOtherBank(bank& ferryBank, bank currentBank, bank otherBank,
                           queue<int>& currentBankCarsQueue, queue<int>& otherBankCarsQueue,
                           int& currentFerryTime, int& nFerryTravelTime)
{
    if (ferryBank == currentBank && currentBankCarsQueue.empty() == false) {
        if (otherBankCarsQueue.empty() == false) {
            if (otherBankCarsQueue.front() < currentBankCarsQueue.front()) {
                ferryBank = otherBank;
                currentFerryTime += nFerryTravelTime;
                if (currentFerryTime < otherBankCarsQueue.front())
                    currentFerryTime = otherBankCarsQueue.front();
            }
            else {
                ferryBank = currentBank;
                currentFerryTime += currentBankCarsQueue.front();
            }
        }
        else {
            ferryBank = currentBank;
            currentFerryTime += currentBankCarsQueue.front();
        }
    }
}

int LoadAndMoveCars(queue<int>& carsQueue, map<int, int>& carTimesMap, int& currentFerryTime, int& nFerryTravelTime, int& nCars)
{
    int nCarsLoaded = 0;

    while (carsQueue.empty() == false) {
        if (carsQueue.front() <= currentFerryTime) {
            if (nCarsLoaded <= nCars) {
                ++nCarsLoaded;
                //carTimesMap[leftBankCarsQueue.front()] = leftBankCarsQueue.front() + nFerryTravelTime;
                carTimesMap[carsQueue.front()] = nFerryTravelTime;
                carsQueue.pop();
            }
            else {
                break;
            }
        }
        else {
            break;
        }
    }
    return nCarsLoaded;
}

int main()
{
    queue<int> leftBankCarsQueue;
    queue<int> rightBankCarsQueue;
    queue<int> allCarsQueue;
    map<int, int> carTimesMap;
    bank ferryBank = leftbank;

    int nFerryTravelTime = 0;
    int nCases = 0;
    int nCars = 0;
    char side[6] = {' '};
    int nLines = 0;
    int nCarArrivalTime = 0;
    int currentFerryTime = 0;
    int nLeftCarsLoaded = 0;
    int nRightCarsLoaded = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++ i) {
        cin >> nCars >> nFerryTravelTime >> nLines;

        carTimesMap = map<int, int>();
        leftBankCarsQueue = queue<int>();
        rightBankCarsQueue = queue<int>();
        allCarsQueue = queue<int>();
        ferryBank = leftbank;
        currentFerryTime = 0;

        for (int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
            if (strcmp(side, "left") == 0) {
                leftBankCarsQueue.push (nCarArrivalTime);
            }
            else {
                rightBankCarsQueue.push (nCarArrivalTime);
            }

            allCarsQueue.push(nCarArrivalTime);
        }

        while (1) {
            if (leftBankCarsQueue.empty() && rightBankCarsQueue.empty())
                break;

            nLeftCarsLoaded = 0;
            if (ferryBank == leftbank) {
                nLeftCarsLoaded = LoadAndMoveCars(leftBankCarsQueue, carTimesMap, currentFerryTime, nFerryTravelTime, nCars);
            }

            if (nLeftCarsLoaded != 0) {
                ferryBank = rightbank;
                currentFerryTime += nFerryTravelTime;
            }

            nRightCarsLoaded = 0;
            if (ferryBank == rightbank) {
                nRightCarsLoaded = LoadAndMoveCars(rightBankCarsQueue, carTimesMap, currentFerryTime, nFerryTravelTime, nCars);
            }

            if (nRightCarsLoaded != 0) {
                ferryBank = leftbank;
                currentFerryTime += nFerryTravelTime;
            }

            // wait at the left bank? or move to the right?
            StayOrMoveToOtherBank(ferryBank, leftbank, rightbank, leftBankCarsQueue, rightBankCarsQueue, currentFerryTime, nFerryTravelTime);

            // wait at the right bank? or move to the left?
            StayOrMoveToOtherBank(ferryBank, rightbank, leftbank, rightBankCarsQueue, leftBankCarsQueue, currentFerryTime, nFerryTravelTime);

            cout << endl;
        }
    }
    return 0;
}
