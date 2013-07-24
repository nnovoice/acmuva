#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > numbers;
    int totalCost = 0;
    int currentCost = 0;
    int nNumbers = 0;
    int num = 0;

    while (cin >> nNumbers) {
        if (nNumbers == 0) break;

        totalCost = 0;

        for (int i = 0; i < nNumbers; ++i) {
            cin >> num;
            numbers.push(num);
        }

        while (numbers.empty() == false) {
            currentCost = numbers.top();
            numbers.pop();

            if (numbers.empty() == false) {
                currentCost += numbers.top();
                numbers.pop();

                totalCost += currentCost;
                numbers.push(currentCost);
            }
            else {
                totalCost += currentCost;
            }
        }

        cout << totalCost << endl;
    }
    return 0;
}

