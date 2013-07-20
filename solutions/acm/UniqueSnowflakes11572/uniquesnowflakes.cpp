/* UVa 11572 - Unique Snowflakes*/
#define MAXSNOWFLAKES 1000002
#include <iostream>
#include <map>
#include <string.h>
#include <cstdio>
using namespace std;

unsigned int snowFlakesVector[MAXSNOWFLAKES];
//unsigned int snowFlakesArr[MAXSNOWFLAKES];

//void printFullVector(vector<unsigned int> snowflakesVector)
//{
//    //cout << "Debug: " << "Full Vector contents: ";
//    for (unsigned int i = 0; i < snowflakesVector.size(); ++i)
//        cout << snowflakesVector[i] << " ";
//    cout << endl;
//}

void printFullVector(unsigned int snowflakesVector[MAXSNOWFLAKES], unsigned int index)
{
    //cout << "Debug: " << "Full Vector contents: ";
    for (unsigned int i = 1; i <= index; ++i)
        cout << snowflakesVector[i] << " ";
    cout << endl;
}

//void printVector(vector<unsigned int> snowflakesVector, unsigned int index)
//{
//    //cout << "Debug: " << "Vector contents from index: " << index << ": ";
//    for (unsigned int i = index; i < snowflakesVector.size(); ++i)
//        cout << snowflakesVector[i] << " ";
//    cout << endl;
//}

void printMap(map<unsigned int, unsigned int> snowflakesMap)
{
    //cout << "Debug: " << "Full Map contents: ";

    map<unsigned int, unsigned int>::iterator snowflakesMapIter = snowflakesMap.begin();
    map<unsigned int, unsigned int>::iterator snowflakesMapEndIter = snowflakesMap.end();

    for (;snowflakesMapIter != snowflakesMapEndIter; ++snowflakesMapIter) {
            cout << (*snowflakesMapIter).first << ":" << (*snowflakesMapIter).second << " ";
    }
    cout << endl;
}

int main()
{
    //freopen ("C:\\data\\personal\\programming\\acm\\input_files\\UniqueSnowFlakes11572\\max.txt", "r", stdin);

    unsigned int nCases = 0;
    map<unsigned int, unsigned int> snowFlakesMap;

    unsigned int nInputSnowflakes = 0;
    unsigned int nPossibleSnowflakesInCurrentPackage = 0;
    unsigned int snowFlake = 0;
    unsigned int nMaxSnowFlakes = 0;
    unsigned int lastSnowFlakeIndex = 0;

    cin >> nCases;
    for (unsigned int cases = 0; cases < nCases; ++cases) {
        nMaxSnowFlakes = 0;
        snowFlakesMap.clear();
        memset (snowFlakesVector, 0, sizeof(unsigned int) * MAXSNOWFLAKES);
        lastSnowFlakeIndex = 1;

        cin >> nInputSnowflakes;

        for (unsigned int index = 1; index <= nInputSnowflakes; ++index) {
            cin >> snowFlake;

            //snowFlakesVector.push_back(snowFlake);
            snowFlakesVector[index] = snowFlake;
            //cout << "Debug: " << "Got new snowflake= " << snowFlake << endl;
            //printFullVector(snowFlakesVector, index);
            //printMap(snowFlakesMap);

            if (snowFlakesMap[snowFlake] != 0) {
                //cout << "Debug: " << "Saw snowflake= " << snowFlake << " at " << snowFlakesMap[snowFlake] << endl;
                //printVector(snowFlakesVector, lastSnowFlakeIndex);

                nPossibleSnowflakesInCurrentPackage = snowFlakesMap.size();

                for (unsigned int j = lastSnowFlakeIndex; j <= snowFlakesMap[snowFlake]; ++j) {
                    //cout << "Debug: " << "Index= " << j << " snowFlake= " << snowFlakesVector[j] << endl;
                    if (j == snowFlakesMap[snowFlake]) {
                        lastSnowFlakeIndex = snowFlakesMap[snowFlake] + 1;
                    }
                    snowFlakesMap.erase(snowFlakesVector[j]);
                }

                //printVector(snowFlakesVector, lastSnowFlakeIndex);
                //printMap(snowFlakesMap);

                //cout << "Debug: " << "Index= " << lastSnowFlakeIndex << " snowFlake= " << snowFlakesVector[lastSnowFlakeIndex] << endl;
                if (nMaxSnowFlakes < nPossibleSnowflakesInCurrentPackage) {
                    nMaxSnowFlakes = nPossibleSnowflakesInCurrentPackage;
                    //cout << "Debug: " << "nMaxSnowflakes = " << nMaxSnowFlakes << endl;
                }
            }

            snowFlakesMap[snowFlake] = index;

            if (nMaxSnowFlakes < snowFlakesMap.size()) {
                nMaxSnowFlakes = snowFlakesMap.size();
            }
            //cout << "Debug: " << snowFlake << " is at index= " << snowFlakesMap[snowFlake] << endl;
        }

        cout << nMaxSnowFlakes << endl;
    }
    return 0;
}
