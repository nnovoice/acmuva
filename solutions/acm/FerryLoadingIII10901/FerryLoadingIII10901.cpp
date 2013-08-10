#include <iostream>
#include <queue>
#include <map>

using namespace std;

enum bank {leftbank, rightbank};

void StayOrMoveToOtherBank(bank& ferryBank, bank currentBank, bank otherBank,
                           queue<int>& currentBankCarsQueue, queue<int>& otherBankCarsQueue,
                           int& currentFerryTime, int& nFerryTravelTime)
{
    if (currentBankCarsQueue.empty() == false) {
        if (otherBankCarsQueue.empty() == false) {
            if (otherBankCarsQueue.front() < currentBankCarsQueue.front()) {
                ferryBank = otherBank;
                currentFerryTime += nFerryTravelTime;
                if (currentFerryTime < otherBankCarsQueue.front())
                    currentFerryTime = otherBankCarsQueue.front();
            }
            else {
                ferryBank = currentBank;
                currentFerryTime = currentBankCarsQueue.front();
            }
        }
        else {
            ferryBank = currentBank;
            currentFerryTime = currentBankCarsQueue.front();
        }
    }
    else {
        ferryBank = otherBank;
        if (otherBankCarsQueue.empty() == false) {
            currentFerryTime += nFerryTravelTime;
            if (currentFerryTime < otherBankCarsQueue.front())
                currentFerryTime = otherBankCarsQueue.front();
        }
    }

    cout << "Debug: " << "StayOrMoveToOtherBank: " << "ferry bank= " << ferryBank << " current ferry time= " << currentFerryTime << endl;
}

int LoadAndMoveCars(queue<int>& carsQueue, map<int, int>& carTimesMap,
                    int& currentFerryTime, int& nFerryTravelTime,
                    int& nCars)
{
    int nCarsLoaded = 0;

    while (carsQueue.empty() == false) {
        if (carsQueue.front() <= currentFerryTime) {
            if (nCarsLoaded <= nCars) {
                ++nCarsLoaded;
                carTimesMap[carsQueue.front()] = currentFerryTime + nFerryTravelTime;
                cout << "Debug: " << "car arrival= " << carsQueue.front() << " drop time= " << (currentFerryTime + nFerryTravelTime) << endl;
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

    if (nCarsLoaded != 0)
        currentFerryTime += nFerryTravelTime;

    cout << "Debug: " << "current ferry time= " << currentFerryTime << endl;

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
       // cout << "Debug: " << nCars << " " << nFerryTravelTime << " " << nLines << endl;

        carTimesMap.erase (carTimesMap.begin(), carTimesMap.end());
        leftBankCarsQueue = queue<int>();
        rightBankCarsQueue = queue<int>();
        allCarsQueue = queue<int>();
        ferryBank = leftbank;
        currentFerryTime = 0;

        for (int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
           // cout << "Debug: " << nCarArrivalTime << " " << side << endl;
            if (side[0] == 'l' && side[1] == 'e' && side[2] == 'f' && side[3] == 't') {
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
                nLeftCarsLoaded = LoadAndMoveCars(leftBankCarsQueue, carTimesMap,
                                                  currentFerryTime, nFerryTravelTime,
                                                  nCars);
                cout << "Debug: " << "leftbank cars loaded= " << nLeftCarsLoaded << endl;
            }

            if (nLeftCarsLoaded != 0) {
                ferryBank = rightbank;
                //currentFerryTime += nFerryTravelTime;
            }
            else {
                StayOrMoveToOtherBank(ferryBank, leftbank, rightbank,
                                      leftBankCarsQueue, rightBankCarsQueue,
                                      currentFerryTime, nFerryTravelTime);
            }

            nRightCarsLoaded = 0;
            if (ferryBank == rightbank) {
                nRightCarsLoaded = LoadAndMoveCars(rightBankCarsQueue, carTimesMap,
                                                   currentFerryTime, nFerryTravelTime,
                                                   nCars);
                cout << "Debug: " << "rightbank cars loaded= " << nRightCarsLoaded << endl;
            }

            if (nRightCarsLoaded != 0) {
                ferryBank = leftbank;
                //currentFerryTime += nFerryTravelTime;
            }
            else {
                StayOrMoveToOtherBank(ferryBank, rightbank, leftbank,
                                      rightBankCarsQueue, leftBankCarsQueue,
                                      currentFerryTime, nFerryTravelTime);
            }
        }

        while (allCarsQueue.empty() == false) {
            cout << carTimesMap[allCarsQueue.front()] << endl;
            allCarsQueue.pop();
        }

        cout << endl;
    }

    return 0;
}
