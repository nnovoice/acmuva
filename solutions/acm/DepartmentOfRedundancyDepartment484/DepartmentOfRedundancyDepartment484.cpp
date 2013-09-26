#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main()
{
    int num = 0;
    map<int, int> numOccurrences;
    queue<int> numQueue;
    while (cin >> num) {
        numOccurrences[num] += 1;
        if (numOccurrences[num] == 1) {
            numQueue.push(num);
        }
    }

    while (numQueue.empty() == false) {
        num = numQueue.front();
        cout << num << " " << numOccurrences[num] << endl;
        numQueue.pop();
    }
    return 0;
}
