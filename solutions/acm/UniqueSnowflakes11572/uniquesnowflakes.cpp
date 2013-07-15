#include <iostream>
#include <map>
using namespace std;

int main()
{
    unsigned int nCases = 0;
    map<unsigned int, unsigned int> snowFlakesMap;
    unsigned int nSnowFlakes = 0;
    unsigned int snowFlake = 0;

    cin >> nCases;
    while (nCases--) {
        snowFlakesMap.clear();
        cin >> nSnowFlakes;
        for (unsigned int i = 0; i < nSnowFlakes; ++i) {
            cin >> snowFlake;
            snowFlakesMap[snowFlake] += 1;
        }

        cout << snowFlakesMap.size() << endl;
    }
    return 0;
}
