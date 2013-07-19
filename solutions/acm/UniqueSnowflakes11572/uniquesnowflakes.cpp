/* UVa 11572 - Unique Snowflakes*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    unsigned int nCases = 0;
    map<unsigned int, unsigned int> snowFlakesMap;
    vector<unsigned int> snowFlakesVector;
    unsigned int nInputSnowflakes = 0;
    unsigned int nSnowflakesInCurrentPackage = 0;
    unsigned int snowFlake = 0;
    unsigned int nMaxSnowFlakes = 0;
    unsigned int snowFlakeIndex = 0;

    cin >> nCases;
    while (nCases--) {
        nMaxSnowFlakes = 0;
        snowFlakesMap.clear();

        cin >> nInputSnowflakes;

        for (unsigned int i = 1; i <= nInputSnowflakes; ++i) {
            cin >> snowFlake;

            snowFlakesVector.push_back(snowFlake);

            if (snowFlakesMap[snowFlake] != 0) {
                //cout << "Debug: " << "Saw snowflake= " << snowFlake << " at " << snowFlakesMap[snowFlake] << endl;

                nSnowflakesInCurrentPackage = snowFlakesMap.size();
                for (; snowFlakesVector[snowFlakeIndex] != snowFlake; ++snowFlakeIndex) {
                    //cout << "Debug: " << "Index= " << snowFlakeIndex << " snowFlake= " << snowFlakesVector[snowFlakeIndex] << endl;
                    snowFlakesMap.erase(snowFlakesVector[snowFlakeIndex]);
                }

                if (snowFlakesVector[snowFlakeIndex] == snowFlake)
                    ++snowFlakeIndex;

                //cout << "Debug: " << "Index= " << snowFlakeIndex << " snowFlake= " << snowFlakesVector[snowFlakeIndex] << endl;
                snowFlakesMap.erase(snowFlake);

                if (nMaxSnowFlakes < nSnowflakesInCurrentPackage) {
                    nMaxSnowFlakes = nSnowflakesInCurrentPackage;
                    //cout << "Debug: " << "nMaxSnowflakes = " << nMaxSnowFlakes << endl;
                }
            }
            else {
                if (nMaxSnowFlakes < snowFlakesMap.size()) {
                    nMaxSnowFlakes = snowFlakesMap.size();
                }
            }

            snowFlakesMap[snowFlake] = i;
            //cout << "Debug: " << snowFlake << " is at index= " << snowFlakesMap[snowFlake] << endl;
        }

        cout << nMaxSnowFlakes << endl;
    }
    return 0;
}
