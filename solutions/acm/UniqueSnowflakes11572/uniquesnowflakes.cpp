/* UVa 11572 - Unique Snowflakes*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    unsigned int nCases = 0;
    map<unsigned int, unsigned int> snowFlakesMap;
    unsigned int nSnowFlakes = 0;
    unsigned int snowFlake = 0;
    unsigned int nMaxSnowFlakes = 0;
    unsigned int diff = 0;
    int leftElem = 0;
    int rightElem = 0;

    cin >> nCases;
    while (nCases--) {
        nMaxSnowFlakes = 0;
        snowFlakesMap.clear();
        leftElem = 1;

        cin >> nSnowFlakes;

        for (unsigned int i = 1; i <= nSnowFlakes; ++i) {
            cin >> snowFlake;
            rightElem = i;

            if (snowFlakesMap[snowFlake] != 0) {
                diff = rightElem - leftElem;
                cout << "Debug: " << "Saw snowflake= " << snowFlake << " at " << snowFlakesMap[snowFlake] << " with diff= " << diff << endl;
                if (diff > nMaxSnowFlakes) {
                    nMaxSnowFlakes = diff;
                }
                leftElem = snowFlakesMap[snowFlake] + 1;
            }

            snowFlakesMap[snowFlake] = i;
            cout << "Debug: " << snowFlake << " is at index= " << snowFlakesMap[snowFlake] << endl;
        }

        cout << nMaxSnowFlakes << endl;
    }
    return 0;
}
