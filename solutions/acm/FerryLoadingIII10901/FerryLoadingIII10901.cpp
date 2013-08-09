#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

enum bank {left, right};

void StayOrMoveToOtherBank(bank& ferryBank, bank& currentBank, bank& otherBank,
                           queue<int>& currentBankCarsQueue, queue<int>& otherBankCarsQueue,
                           int& currentFerryTime, int& nFerryTravelTime)
{
    if (ferryBank == currentBank && currentBankCarsQueue.empty() == false) {
        if (otherBankCarsQueue.empty() == false) {
            if (otherBankCarsQueue.top() < currentBankCarsQueue.top()) {
                ferryBank = otherBank;
                currentFerryTime += nFerryTravelTime;
                if (currentFerryTime < otherBankCarsQueue.top())
                    currentFerryTime = otherBankCarsQueue.top();
            }
            else {
                ferryBank = currentBank;
                currentFerryTime += currentBankCarsQueue.top();
            }
        }
        else {
            ferryBank = currentBank;
            currentFerryTime += currentBankCarsQueue.top();
        }
    }
}

int LoadAndMoveCars(queue<int>& carsQueue, map<int, int>& carTimesMap, int& currentFerryTime, int& nFerryTravelTime)
{
    int nCarsLoaded = 0;
    if (ferryBank == left) {
        while (carsQueue.empty() == false) {
            if (carsQueue.top() <= currentFerryTime) {
                if (nCarsLoaded <= nCars) {
                    ++nCarsLoaded;
                    //carTimesMap[leftBankCarsQueue.top()] = leftBankCarsQueue.top() + nFerryTravelTime;
                    carTimesMap[carsQueue.top()] = nFerryTravelTime;
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
    }
    return nCarsLoaded;
}

int main()
{
    queue<int> leftBankCarsQueue;
    queue<int> rightBankCarsQueue;
    queue<int> allCarsQueue;
    map<int, int> carTimesMap;
    bank ferryBank = left;

    int nFerryTravelTime = 0;
    int nCases = 0;
    int nCars = 0;
    char side[6] = {' '};
    int nLines = 0;
    int nCarArrivalTime = 0;
    int currentFerryTime = 0;
    int nLeftCarsLoaded = 0;
    int nRightCarsLoaded = 0;
    int diffTime = 0;

    cin >> nCases;
    for (int i = 0; i < nCases; ++ i) {
        cin >> nCars >> nFerryTravelTime >> nLines;

        carTimesMap = map<int, int>();
        leftBankCarsQueue = queue<int>();
        rightBankCarsQueue = queue<int>();
        allCarsQueue = queue<int>();
        ferryBank = left;
        currentFerryTime = 0;

        for (int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
            if (strcmp(side, "left") == 0) {
                leftBankCars.push (nCarArrivalTime);
            }
            else {
                rightBankCars.push (nCarArrivalTime);
            }

            allCarsQueue.push(nCarArrivalTime);
        }

        while (1) {
            if (leftBankCarsQueue.empty() && rightBankCarsQueue.empty())
                break;

            nLeftCarsLoaded = 0;
            if (ferryBank == left) {
                nLeftCarsLoaded = LoadAndMoveCars(leftBankCarsQueue, carTimesMap, currentFerryTime, nFerryTravelTime);
            }

            if (nLeftCarsLoaded != 0) {
                ferryBank = right;
                currentFerryTime += nFerryTravelTime;
            }

            nRightCarsLoaded = 0;
            if (ferryBank == right) {
                nRightCarsLoaded = LoadAndMoveCars(rightBankCarsQueue, carTimesMap, currentFerryTime, nFerryTravelTime);)
            }

            if (nRightCarsLoaded != 0) {
                ferryBank = left;
                currentFerryTime += nFerryTravelTime;
            }

            // wait at the left bank? or move to the right?
            StayOrMoveToOtherBank(ferryBank, left, right, leftBankCarsQueue, rightBankCarsQueue, currentFerryTime, nFerryTravelTime);
//            if (ferryBank == left && leftBankCarsQueue.empty() == false) {
//                if (rightBankCarsQueue.empty() == false) {
//                    if (rightBankCarsQueue.top() < leftBankCarsQueue.top()) {
//                        ferryBank = right;
//                        currentFerryTime += nFerryTravelTime;
//                        if (currentFerryTime < rightBankCarsQueue.top())
//                            currentFerryTime = rightBankCarsQueue.top();
//                    }
//                    else {
//                        ferryBank = left;
//                        currentFerryTime += leftBankCarsQueue.top();
//                    }
//                }
//                else {
//                    ferryBank = left;
//                    currentFerryTime += leftBankCarsQueue.top();
//                }
            }

            // wait at the right bank? or move to the left?
//            bank& ferryBank, bank& currentBank, bank& otherBank,
//                           queue<int>& currentBankCarsQueue, queue<int>& otherBankCarsQueue,
//                           int& currentFerryTime, int& nFerryTravelTime
            StayOrMoveToOtherBank(ferryBank, right, left, rightBankCarsQueue, leftBankCarsQueue, currentFerryTime, nFerryTravelTime);
//            if (ferryBank == right && rightBankCarsQueue.empty() == false) {
//                if (leftBankCarsQueue.empty() == false) {
//                    if (leftBankCarsQueue.top() < rightBankCarsQueue.top()) {
//                        ferryBank = left;
//                        currentFerryTime += nFerryTravelTime;
//                        if (currentFerryTime < leftBankCarsQueue.top())
//                            currentFerryTime = leftBankCarsQueue.top();
//                    }
//                    else {
//                        ferryBank = right;
//                        currentFerryTime += rightBankCarsQueue.top();
//                    }
//                }
//                else {
//                    ferryBank = right;
//                    currentFerryTime += rightBankCarsQueue.top();
//                }
//            }
        }

        cout << endl;
    }
    return 0;
}
