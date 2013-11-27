#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <cstdio>

using namespace std;

enum bank {leftbank, rightbank};

void InsertItemIntoMapItemList(map<int, list<int> >& bankTimesIdsMap, int& key, int& item)
{
    cout << "Debug: " << "key= " << key << " item= " << item << endl;
    list<int>* pItemList = 0;
    if (bankTimesIdsMap.find(key) != bankTimesIdsMap.end()) {
        pItemList = &bankTimesIdsMap[key];
        pItemList->push_back(item);
    }
    else {
        list<int>* pItemList = new list<int>();
        pItemList->push_back(item);
        bankTimesIdsMap[key] = *pItemList;
    }
}

int GetItemFromMapItemList(map<int, list<int> >& bankTimesIdsMap, int& key)
{
    int item = 0;
    list<int>* pItemList;
    if (bankTimesIdsMap.find(key) != bankTimesIdsMap.end()) {
        pItemList = &bankTimesIdsMap[key];
        item = pItemList->front();
        pItemList->pop_front();
    }
    return item;
}

void MoveToOtherBank (bank& ferryBank, bank currentBank, bank otherBank,
                      queue<int>& otherBankCarsQueue, int& currentFerryTime, int& nFerryTravelTime)
{
    ferryBank = otherBank;

	// wait until the car arrives
	if (currentFerryTime < otherBankCarsQueue.front()) // LEARNING: i had blindly assigned the current ferry time to the front
		currentFerryTime = otherBankCarsQueue.front();

	// travel to pick it up
    currentFerryTime += nFerryTravelTime;
}

void StayIntheCurrentBank(bank& ferryBank, bank currentBank, bank otherBank,
                      queue<int>& currentBankCarsQueue, int& currentFerryTime, int& nFerryTravelTime)
{
    ferryBank = currentBank;
    currentFerryTime = currentBankCarsQueue.front();
}

void StayOrMoveToOtherBank(bank& ferryBank, bank currentBank, bank otherBank,
                           queue<int>& currentBankCarsQueue, queue<int>& otherBankCarsQueue,
                           int& currentFerryTime, int& nFerryTravelTime)
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

int LoadAndMoveCars(bank& ferryBank,
                    queue<int>& carsQueue,
                    map<int, list<int> >& carIDsMap,
                    map<int, list<int> >& carTimesMap,
                    map<int, int>& carIDsToDropTimesMap,
                    int& currentFerryTime,
                    int& nFerryTravelTime,
                    int& nCars)
{
    int nCarsLoaded = 0;
    int carID = 0;

    while (carsQueue.empty() == false) {
        if (carsQueue.front() <= currentFerryTime) {
            if (nCarsLoaded < nCars) { // LEARNING: subtle bug here: instead of <, i had <= which caused trouble
                ++nCarsLoaded;
                carID = GetItemFromMapItemList(carIDsMap, carsQueue.front());
                carIDsToDropTimesMap[carID] = (currentFerryTime + nFerryTravelTime);
                cout << "Debug: " << "car arrival= " << carsQueue.front() << "carID= " << carID << " drop time= " << (currentFerryTime + nFerryTravelTime) << " from the map= " << carIDsToDropTimesMap[carID] << endl;
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

void PrintMap(map<int, list<int> > bankCarTimesMap)
{
    map<int, list<int> >::iterator iter = bankCarTimesMap.begin();
    map<int, list<int> >::iterator iterEnd = bankCarTimesMap.end();
    list<int>* pList;
    list<int>::iterator listIter;
    list<int>::iterator listIterEnd;
    for (; iter != iterEnd; ++iter) {
        *pList = iter->second;
        listIter = pList->begin();
        listIterEnd = pList->end();
        cout << "Debug: " << "values in the list: " << endl;
        for (; listIter != listIterEnd; ++listIter)
            cout << " " << *listIter << " ";
        cout << endl;
    }
}


int main()
{
    queue<int> leftBankCarsQueue;
    queue<int> rightBankCarsQueue;
    queue<int> allCarsQueue;
    map<int, list<int> > leftBankCarTimesMap;
    map<int, list<int> > leftBankCarIDsMap;
    map<int, list<int> > rightBankCarTimesMap;
    map<int, list<int> > rightBankCarIDsMap;
    map<int, int> carIDsToDropTimesMap;
	int carID = 0;

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

    //freopen ("C:\\data\\personal\\programming\\acm\\input_files\\FerryLoadingIII10901\\ferry3.txt", "r", stdin);
    //C:\data\personal\programming\acm\input_files\FerryLoadingIII10901
    cin >> nCases;
    for (int i = 0; i < nCases; ++i) {
        cin >> nCars >> nFerryTravelTime >> nLines;
        //cout << "Debug: " << nCars << " " << nFerryTravelTime << " " << nLines << endl;

        leftBankCarTimesMap = map<int, list<int> >();
        leftBankCarIDsMap = map<int, list<int> >();
        rightBankCarTimesMap = map<int, list<int> >();
        rightBankCarIDsMap = map<int, list<int> >();
        carIDsToDropTimesMap = map<int, int>();
        leftBankCarsQueue = queue<int>();
        rightBankCarsQueue = queue<int>();
        allCarsQueue = queue<int>();
        ferryBank = leftbank;
        currentFerryTime = 0;
		carID = 0;

        for (int j = 0; j < nLines; ++j) {
            cin >> nCarArrivalTime >> side;
            //cout << "Debug: " << nCarArrivalTime << " " << side << endl;
            if (side[0] == 'l' && side[1] == 'e' && side[2] == 'f' && side[3] == 't') {
                leftBankCarsQueue.push (nCarArrivalTime);
				InsertItemIntoMapItemList(leftBankCarTimesMap, nCarArrivalTime, carID);
				InsertItemIntoMapItemList(leftBankCarIDsMap, carID, nCarArrivalTime);
            }
            else {
                rightBankCarsQueue.push (nCarArrivalTime);
                InsertItemIntoMapItemList(rightBankCarTimesMap, nCarArrivalTime, carID);
                InsertItemIntoMapItemList(rightBankCarIDsMap, carID, nCarArrivalTime);
            }
            allCarsQueue.push(carID);
            ++carID;
        }

        cout << "Debug: " << " leftBankCarTimesMap:" << endl;
        PrintMap(leftBankCarTimesMap);
        cout << "Debug: " << " leftBankCarIDsMap:" << endl;
        PrintMap(leftBankCarIDsMap);
        cout << "Debug: " << " rightBankCarTimesMap:" << endl;
        PrintMap(rightBankCarTimesMap);
        cout << "Debug: " << " rightBankCarIDsMap:" << endl;
        PrintMap(rightBankCarIDsMap);

        while (1) {
            if (leftBankCarsQueue.empty() && rightBankCarsQueue.empty())
                break;

            //cout << "Debug: " << "current bank = " << ferryBank << " current ferry time= " << currentFerryTime << endl;

            nLeftCarsLoaded = 0;
            if (ferryBank == leftbank) {
                nLeftCarsLoaded = LoadAndMoveCars(ferryBank, leftBankCarsQueue,
                                                  leftBankCarIDsMap, leftBankCarTimesMap,
                                                  carIDsToDropTimesMap,
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
                                                   carIDsToDropTimesMap,
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
            cout << "Debug: " << "CarID= " << allCarsQueue.front() << endl;
            cout << carIDsToDropTimesMap[allCarsQueue.front()] << endl;
            allCarsQueue.pop();
        }

        if (i < (nCases - 1))
            cout << endl;
    }

    return 0;
}
