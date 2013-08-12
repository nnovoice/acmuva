#include <iostream>
#include <queue>
#include <map>

using namespace std;

enum bank {leftbank, rightbank};
void MoveToOtherBank (bank& ferryBank, bank currentBank, bank otherBank,
                      queue<unsigned int>& otherBankCarsQueue, unsigned int& currentFerryTime, unsigned int& nFerryTravelTime)
{
    ferryBank = otherBank;
    // wait until the car arrives
    currentFerryTime = otherBankCarsQueue.front();
    // travel to pick it up
    currentFerryTime += nFerryTravelTime;
}
void StayIntheCurrentBank(bank& ferryBank, bank currentBank, bank otherBank,
                      queue<unsigned int>& currentBankCarsQueue, unsigned int& currentFerryTime, unsigned int& nFerryTravelTime)
{
    ferryBank = currentBank;
    currentFerryTime = currentBankCarsQueue.front();
}

void StayOrMoveToOtherBank(bank& ferryBank, bank currentBank, bank otherBank,
                           queue<unsigned int>& currentBankCarsQueue, queue<unsigned int>& otherBankCarsQueue,
                           unsigned int& currentFerryTime, unsigned int& nFerryTravelTime)
{
    if (currentBankCarsQueue.empty() == false && otherBankCarsQueue.empty() == false) {
        if (currentBankCarsQueue.front() < otherBankCarsQueue.front()) {
            StayIntheCurrentBank(ferryBank, currentBank, otherBank, currentBankCarsQueue, currentFerryTime, nFerryTravelTime);
        }
        else {
            MoveToOtherBank (ferryBank, currentBank, otherBank, otherBankCarsQueue, currentFerryTime, nFerryTravelTime);
        }
    }
    else if (otherBankCarsQueue.empty() == false) {
        MoveToOtherBank (ferryBank, currentBank, otherBank, otherBankCarsQueue, currentFerryTime, nFerryTravelTime);
    }
    else if (currentBankCarsQueue.empty() == false) {
        StayIntheCurrentBank(ferryBank, currentBank, otherBank, currentBankCarsQueue, currentFerryTime, nFerryTravelTime);
    }

    //cout << "Debug: " << "StayOrMoveToOtherBank: " << "ferry bank= " << ferryBank << " current ferry time= " << currentFerryTime << endl;
}

unsigned int LoadAndMoveCars(queue<unsigned int>& carsQueue, map<unsigned int, unsigned int>& carTimesMap,
                    unsigned int& currentFerryTime, unsigned int& nFerryTravelTime,
                    unsigned int& nCars)
{
    unsigned int nCarsLoaded = 0;

    while (carsQueue.empty() == false) {
        if (carsQueue.front() <= currentFerryTime) {
            if (nCarsLoaded < nCars) { // LEARNING: subtle bug here: instead of <, i had <= which caused trouble
                ++nCarsLoaded;
                carTimesMap[carsQueue.front()] = currentFerryTime + nFerryTravelTime;
                //cout << "Debug: " << "car arrival= " << carsQueue.front() << " drop time= " << (currentFerryTime + nFerryTravelTime) << endl;
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

    //cout << "Debug: " << "current ferry time= " << currentFerryTime << endl;

    return nCarsLoaded;
}

int main()
{
    queue<unsigned int> leftBankCarsQueue;
    queue<unsigned int> rightBankCarsQueue;
    queue<unsigned int> allCarsQueue;
    map<unsigned int, unsigned int> carTimesMap;
    bank ferryBank = leftbank;

    unsigned int nFerryTravelTime = 0;
    unsigned int nCases = 0;
    unsigned int nCars = 0;
    char side[6] = {' '};
    unsigned int nLines = 0;
    unsigned int nCarArrivalTime = 0;
    unsigned int currentFerryTime = 0;
    unsigned int nLeftCarsLoaded = 0;
    unsigned int nRightCarsLoaded = 0;

    cin >> nCases;
    for (unsigned int i = 0; i < nCases; ++i) {
        cin >> nCars >> nFerryTravelTime >> nLines;
       // //cout << "Debug: " << nCars << " " << nFerryTravelTime << " " << nLines << endl;

        carTimesMap.erase (carTimesMap.begin(), carTimesMap.end());
        leftBankCarsQueue = queue<unsigned int>();
        rightBankCarsQueue = queue<unsigned int>();
        allCarsQueue = queue<unsigned int>();
        ferryBank = leftbank;
        currentFerryTime = 0;

        for (unsigned int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
           // //cout << "Debug: " << nCarArrivalTime << " " << side << endl;
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

            //cout << "Debug: " << "current bank = " << ferryBank << " current ferry time= " << currentFerryTime << endl;

            nLeftCarsLoaded = 0;
            if (ferryBank == leftbank) {
                nLeftCarsLoaded = LoadAndMoveCars(leftBankCarsQueue, carTimesMap,
                                                  currentFerryTime, nFerryTravelTime,
                                                  nCars);
                //cout << "Debug: " << "leftbank cars loaded= " << nLeftCarsLoaded << endl;

                if (nLeftCarsLoaded != 0) {
                    ferryBank = rightbank;
                }
                else {
                    StayOrMoveToOtherBank(ferryBank, leftbank, rightbank,
                                      leftBankCarsQueue, rightBankCarsQueue,
                                      currentFerryTime, nFerryTravelTime);
                }
            }

            nRightCarsLoaded = 0;
            if (ferryBank == rightbank) {
                nRightCarsLoaded = LoadAndMoveCars(rightBankCarsQueue, carTimesMap,
                                                   currentFerryTime, nFerryTravelTime,
                                                   nCars);
                //cout << "Debug: " << "rightbank cars loaded= " << nRightCarsLoaded << endl;

                if (nRightCarsLoaded != 0) {
                    ferryBank = leftbank;
                }
                else {
                    StayOrMoveToOtherBank(ferryBank, rightbank, leftbank,
                                          rightBankCarsQueue, leftBankCarsQueue,
                                          currentFerryTime, nFerryTravelTime);
                }
            }
        }

        while (allCarsQueue.empty() == false) {
            cout << carTimesMap[allCarsQueue.front()] << endl;
            allCarsQueue.pop();
        }

        if (i < (nCases - 1))
            cout << endl;
    }

    return 0;
}
