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
    unsigned int mMaxSnowFlakes = 0;

    cin >> nCases;
    while (nCases--) {
        mMaxSnowFlakes = 0;
        snowFlakesMap.clear();
        cin >> nSnowFlakes;
        for (unsigned int i = 0; i < nSnowFlakes; ++i) {
            cin >> snowFlake;
            if (snowFlakesMap[snowFlake] == 1) {
                if (mMaxSnowFlakes < snowFlakesMap.size()) {
                    mMaxSnowFlakes = snowFlakesMap.size();
                }
                //snowFlakesMap.clear();
            }
            else {
                snowFlakesMap[snowFlake] += 1;
            }


        }

        cout << mMaxSnowFlakes << endl;
    }
    return 0;
}
