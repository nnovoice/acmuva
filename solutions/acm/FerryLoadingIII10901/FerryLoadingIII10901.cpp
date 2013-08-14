#include <iostream>
#include <queue>
#include <map>
#include <cstdio>

using namespace std;

enum bank {leftbank, rightbank};
void MoveToOtherBank (bank& ferryBank, bank currentBank, bank otherBank,
                      queue<unsigned int>& otherBankCarsQueue, unsigned int& currentFerryTime, unsigned int& nFerryTravelTime)
{
    ferryBank = otherBank;

	// wait until the car arrives
	if (currentFerryTime < otherBankCarsQueue.front()) // LEARNING: i had blindly assigned the current ferry time to the front
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
    //cout << "Debug: " << "StayOrMoveToOtherBank: " << "ferry bank= " << ferryBank << " current ferry time= " << currentFerryTime << endl;
    if (currentBankCarsQueue.empty() == false && otherBankCarsQueue.empty() == false) {
        if (currentBankCarsQueue.front() <= otherBankCarsQueue.front()) { // LEARNING: subtle bug here: instead of <=, i had < which caused trouble
            StayIntheCurrentBank(ferryBank, currentBank, otherBank, currentBankCarsQueue, currentFerryTime, nFerryTravelTime);
        }
        else {
            MoveToOtherBank (ferryBank, currentBank, otherBank, otherBankCarsQueue, currentFerryTime, nFerryTravelTime);
        }
    }
    else if (currentBankCarsQueue.empty() == false) {
        StayIntheCurrentBank(ferryBank, currentBank, otherBank, currentBankCarsQueue, currentFerryTime, nFerryTravelTime);
    }
    else if (otherBankCarsQueue.empty() == false) {
        MoveToOtherBank (ferryBank, currentBank, otherBank, otherBankCarsQueue, currentFerryTime, nFerryTravelTime);
    }
    //cout << "Debug: " << "StayOrMoveToOtherBank: " << "ferry bank= " << ferryBank << " current ferry time= " << currentFerryTime << endl;
}

unsigned int LoadAndMoveCars(bank& ferryBank, queue<unsigned int>& carsQueue,
                            map<unsigned int, unsigned int>& carIDsMap, map<unsigned int, unsigned int>& carTimesMap,
                            unsigned int& currentFerryTime, unsigned int& nFerryTravelTime,
                            unsigned int& nCars)
{
    unsigned int nCarsLoaded = 0;
    unsigned int carID = 0;

    while (carsQueue.empty() == false) {
        if (carsQueue.front() <= currentFerryTime) {
            if (nCarsLoaded < nCars) { // LEARNING: subtle bug here: instead of <, i had <= which caused trouble
                ++nCarsLoaded;
                carID = carTimesMap[carsQueue.front()];
                carIDsMap[carID] = (currentFerryTime + nFerryTravelTime);
                //cout << "Debug: " << "car arrival= " << carsQueue.front() << "carID= " << carID << " drop time= " << (currentFerryTime + nFerryTravelTime) << " from the map= " << carIDsMap[carID] << endl;
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
    map<unsigned int, unsigned int> leftBankCarTimesMap;
    map<unsigned int, unsigned int> leftBankCarIDsMap;
    map<unsigned int, unsigned int> rightBankCarTimesMap;
    map<unsigned int, unsigned int> rightBankCarIDsMap;
	unsigned int carID = 0;
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

    //freopen ("C:\\data\\personal\\programming\\acm\\input_files\\FerryLoadingIII10901\\ferry3.txt", "r", stdin);
    //C:\data\personal\programming\acm\input_files\FerryLoadingIII10901
    cin >> nCases;
    for (unsigned int i = 0; i < nCases; ++i) {
        cin >> nCars >> nFerryTravelTime >> nLines;
        //cout << "Debug: " << nCars << " " << nFerryTravelTime << " " << nLines << endl;

        leftBankCarTimesMap = map<unsigned int, unsigned int>();
        leftBankCarIDsMap = map<unsigned int, unsigned int>();
        rightBankCarTimesMap = map<unsigned int, unsigned int>();
        rightBankCarIDsMap = map<unsigned int, unsigned int>();
        leftBankCarsQueue = queue<unsigned int>();
        rightBankCarsQueue = queue<unsigned int>();
        allCarsQueue = queue<unsigned int>();
        ferryBank = leftbank;
        currentFerryTime = 0;
		carID = 0;

        for (unsigned int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
            //cout << "Debug: " << nCarArrivalTime << " " << side << endl;
            if (side[0] == 'l' && side[1] == 'e' && side[2] == 'f' && side[3] == 't') {
                leftBankCarsQueue.push (nCarArrivalTime);
				leftBankCarTimesMap[nCarArrivalTime] = carID;
				leftBankCarIDsMap[carID] = nCarArrivalTime;
            }
            else {
                rightBankCarsQueue.push (nCarArrivalTime);
                rightBankCarTimesMap[nCarArrivalTime] = carID;
                rightBankCarIDsMap[carID] = nCarArrivalTime;
            }
            allCarsQueue.push(carID);
            ++carID;
        }

        while (1) {
            if (leftBankCarsQueue.empty() && rightBankCarsQueue.empty())
                break;

            //cout << "Debug: " << "current bank = " << ferryBank << " current ferry time= " << currentFerryTime << endl;

            nLeftCarsLoaded = 0;
            if (ferryBank == leftbank) {
                nLeftCarsLoaded = LoadAndMoveCars(ferryBank, leftBankCarsQueue,
                                                  leftBankCarIDsMap, leftBankCarTimesMap,
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
                nRightCarsLoaded = LoadAndMoveCars(ferryBank, rightBankCarsQueue,
                                                   rightBankCarIDsMap, rightBankCarTimesMap,
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
            //cout << "Debug: " << "CarID= " << allCarsQueue.front();
            if (leftBankCarIDsMap.find(allCarsQueue.front()) != leftBankCarIDsMap.end())
                cout << leftBankCarIDsMap[allCarsQueue.front()];
            else if(rightBankCarIDsMap.find(allCarsQueue.front()) != rightBankCarIDsMap.end())
                cout << rightBankCarIDsMap[allCarsQueue.front()];

            cout << endl;
            allCarsQueue.pop();
        }

        if (i < (nCases - 1))
            cout << endl;
    }

    return 0;
}
